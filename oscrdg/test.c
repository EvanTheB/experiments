
void test(const char ** c) {
  return;
}

void test2(const char* c) {
  return;
}



void api(char *test);

int main(int argc, char **argv) {
  char * a = "abc";
  test2(a);
  char ** b = &a;
  test((const char**)b);
  test(b);
}

