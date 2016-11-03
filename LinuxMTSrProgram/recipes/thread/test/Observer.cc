#include <algorithm>
#include <vector>
#include <stdio.h>

class Observable;

class Observer
{
 public:
  virtual ~Observer();
  virtual void update() = 0;

  // 不要直接在构造函数中直接调用 Observable::register_,避免在多线程中半生熟的this对象被调用
  // 增加第二步骤调用
  void observe(Observable* s);

 protected:
  Observable* subject_;  // 多线程环境下该对象调用前有效性无法保证
};

class Observable
{
 public:
  void register_(Observer* x);
  void unregister(Observer* x);

  void notifyObservers()
  {
    for (size_t i = 0; i < observers_.size(); ++i)
    {
      Observer* x = observers_[i];
      // 多线程下仅仅判断指针有效性还不够
      if (x) {
        x->update(); // (3)
      }
    }
  }

 private:
  std::vector<Observer*> observers_;  // 多线程下需要同步原语
};

Observer::~Observer()
{
  subject_->unregister(this);
}

void Observer::observe(Observable* s)
{
  s->register_(this);
  subject_ = s;
}

void Observable::register_(Observer* x)
{
  observers_.push_back(x);
}

void Observable::unregister(Observer* x)
{
  std::vector<Observer*>::iterator it = std::find(observers_.begin(), observers_.end(), x);
  if (it != observers_.end())
  {
    std::swap(*it, observers_.back());
    observers_.pop_back();
  }
}

// ---------------------

class Foo : public Observer
{
  virtual void update()
  {
    printf("Foo::update() %p\n", this);
  }
};

int main()
{
  Foo* p = new Foo;
  Observable subject;
  p->observe(&subject);
  subject.notifyObservers();
  delete p;
  subject.notifyObservers();
}
