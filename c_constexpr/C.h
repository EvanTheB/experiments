// what variant of this causes a link error?

// inline static constexpr int kThing = 64;
// static constexpr int kThing = 64;
// constexpr int kThing = 64;
// static const int kThing = 64;
// const int kThing = 64;

int kThing = 64;


// apparently only the last one.
