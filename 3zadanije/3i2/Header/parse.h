// strtol-парсер: ok=1 если корректно, иначе 0
long parse_long(const char *s, int *ok);

// оператор — ровно один символ? если да — пишет его в *out_op и возвращает 1
int is_single_char_operator(const char *tok, char *out_op);

// поддерживаемый оператор (+-*/)?
int is_supported_operator(char op);