#define MAX_SIZE_STACK 100
#define FALSE 0
#define TRUE 0

// 중위 표기법을 후위 표기법으로 변환한다
// 피연산자는 무조건 출력한다
// 연산자의 경우에는 우선순위에 따라 결정한다

typedef int element;
typedef struct {
	element stack[MAX_SIZE_STACK];
	int top;
}StackType;

void init(StackType *s) {
	s->top = -1;
}

int is_empty(StackType *s) {
	return s->top == -1;
}

int is_full(StackType *s) {
	return s->top == MAX_SIZE_STACK - 1;
}

void push(StackType *s, element item) {
	if (is_full(s))
		exit(1);
	s->stack[++(s->top)] = item;
}

element pop(StackType *s) {
	if (is_empty(s))
		exit(1);
	return s->stack[(s->top)--];
}

element peek(StackType *s) {
	if (is_empty(s))
		exit(1);
	return s->stack[s->top];
}

// 우선순위 반환 메서드
int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

void PostExp(char** exp, char** exp2) {
	int i, j = 0, count = 0;
	char exp3[100] = { 0, };
	char ch, top_op;
	int len = (int)strlen(exp[0]);

	StackType s;
	init(&s);

	while (exp[j] != NULL) {
		for (i = 0; i < len; i++) {
			ch = (int)exp[j][i];

			switch (ch) {
			case '+': case '-': case '*': case '/': // 연산자일 경우

													// 자신보다 우선 순위가 높은 것이
													// Stack에 있을 경우 어서 빼준다
				while (!is_empty(&s) && prec(peek(&s)) >= prec(ch)) {
					top_op = pop(&s);
					exp3[count] = top_op;
					count++;
				}
				push(&s, ch);
				break;

				// 괄호의 경우
			case '(':
				push(&s, ch);
				break;

			case ')':
				top_op = pop(&s);
				while (top_op != '(') {
					exp3[count] = top_op;
					count++;
					top_op = pop(&s);
				}
				break;

				// 피연산자일 경우
			default:
				exp3[count] = ch;
				count++;
				break;
			}
		}

		while (!is_empty(&s)) {
			exp3[count] = pop(&s);
			count++;
		}

		*(exp2) = (char*)malloc(sizeof(char));
		for (i = 0; i < 100; i++) {
			if (i >= count) {
				exp2[j][i] = NULL;
			}
			else {
				exp2[j][i] = exp3[i];
			}
		}
		j++;
	}
}
