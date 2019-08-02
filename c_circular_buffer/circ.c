    #define BUFF_SIZE (4U)
    #define BUFF_SIZE_MASK (BUFF_SIZE-1U)

    struct buffer {
        float buff[BUFF_SIZE];
        unsigned writeIndex;
    };

    void write(struct buffer *buffer, float value) {
        buffer->buff[(++buffer->writeIndex) & BUFF_SIZE_MASK] = value;
    }

    float readn(struct buffer *buffer, unsigned Xn){
        return buffer->buff[(buffer->writeIndex - Xn) & BUFF_SIZE_MASK];
    }

int main(int argc, char const *argv[])
{
    struct buffer buf;
    buf.writeIndex = 0;
    write(&buf, 1.);
    printf("%f\n", readn(&buf, 0));
    write(&buf, 2.);
    printf("%f\n", readn(&buf, 0));
    printf("%f\n", readn(&buf, 1));
    write(&buf, 3.);
    write(&buf, 4.);
    printf("%f\n", readn(&buf, 0));
    write(&buf, 5.);
    printf("%f\n", readn(&buf, 0));
    printf("%f\n", readn(&buf, 1));
    return 0;
}
