#include <utility>
#include <cstdio>

class CallbackBase
{
public:
  inline CallbackBase(CallbackBase&& c) noexcept;
  CallbackBase& operator=(CallbackBase&& c) noexcept;

protected:
  ~CallbackBase();
  constexpr inline CallbackBase();
};

constexpr CallbackBase::CallbackBase() = default;
CallbackBase::CallbackBase(CallbackBase&&) noexcept = default;
CallbackBase& CallbackBase::operator=(CallbackBase&& c) noexcept = default;
CallbackBase::~CallbackBase() = default;

class callback : CallbackBase
{
private:
    int x;
public:
    // callback(int x) : x(x) { printf("constructor\n");};

    constexpr callback(int x) : x(x) {}; //= default;
    callback(std::nullptr_t) = delete;

    callback(const callback&) = delete;
    callback& operator=(const callback&) = delete;

    callback(callback&&) noexcept = default;
    callback& operator=(callback&&) noexcept = default;

    // ~callback();
    void Run()
    {
        printf("%d\n", x);
    }
};

int main(int argc, char const *argv[])
{
    callback x(2);
    callback y = std::move(x);

    // works normal
    x.Run();

    // works
    std::move(x).Run();

    // works
    std::move(x).Run();

    return 0;
}
