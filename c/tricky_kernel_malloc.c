
struct dev {
    int stuff;
    char data[0];
};

struct a
{
    int stuff;
};

struct b
{
    int stuff;
};

void probe_a()
{
    struct dev *d = malloc(sizeof struct dev);
    struct a *aa malloc(sizeof struct a);
    d->data = aa;
}

void probe_b()
{
    struct b *bb = malloc(sizeof struct dev + sizeof struct b);
    bb->d.data = bb;
}

void use(stuct dev *d)
{
    d->
}
