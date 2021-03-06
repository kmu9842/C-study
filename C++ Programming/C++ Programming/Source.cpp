// C++ 가르치는 노하우? 순서?

// 피피티도 참조해보고 뭘 가르칠지 정하자.
// 학기중일 경우에는 애들이 진도 어디까지 나가는가도 물어봐야 한다. 너무 어렵게 나가면 애들 탈주하거나 고딩때 처럼 선배 왕창 깐다...
// 여름방학일 경우에는 그딴거 없다 들어올때는 맘대로지만 나갈때는 아니란다?

// 들어가기전, 내용이 어려울테니 굳이 모두 기억하려고 애쓸필요는 없다고 해주자. 
// 키워드만 알아가는 것만으로도 나중에 찾을 수 있고, 인터넷에 정보는 넘쳐나니까.

// -> 타입부터 가르치자 
// int크기 들때 메이플예시로 들어보자. 재밌을거 같다.
// int는 4바이트라는건 표준이 아니라는 것을 알려주자. 생각보다 애들이 자주 놓치는 부분이다. 다른 자료형도 마찬가지인걸 알려주고.

// 아스키코드는 물어보고 넘어가든가 하자. 교수님이 설명을 안해주실리가...

// 1 = sizeof(char) <= sizeof(short)
//				    <= sizeof(int)
//				    <= sizeof(long)
// 이게 표준적인 자료형들의 크기. 알려주자.

// 비야네옹도 한번 알려주자. C++의 창시자신데 모르면 섭하지.

// C++의 설계원칙
// 로우 레벨 프렌들리 - 하드의 깊은곳까지 손댈 수 있도록. 포인터가 대표적 예시
// 제로 오버로드		 - 자바와 확연한 차이점. 예외처리를 강제하지는 않는다. 다만 책임은 유저가. 설명하기전 자바의 트라이 캐치를 좀 설명해줘야 할거 같다.

// type?
// 크게 두가지로 나뉜다. 정수? 실수?
// 정수 표현하는거로 뭐가 나와? int(4) 그 외에도 엄청 많지. byte short같은건 우리같은 클라이언트보다 패킷같은걸 쓰는, 패킷의 사이즈를 줄여야 하는 서버에서 더 많이 쓸거야.
// 실수는? double이 나오지. 

// -> 잠깐 반복문 이야기를 해보면,
// 실수형에 대한걸 주의 시킨다.
// for (float i = 0.0f;i<10.0f;i++)
//	if (i == 8.0f) break;
// 8번째에서 멈추지 않는다. 부동소수점 문제는 유니티에서도 많이 하는 실수가 될거니 설명해주자.

// 컴퓨터는 소수점을 어떻게 표현하느냐?
// 일단 두가지 방법으로 나뉜다. 고정소수점과 부동소수점.
// 요즘은 거의 부동소수점으로 표현한다. 당연히 무한대의 소수점은 만들수 없고 유효한계가 있다.
// 플롯은 보통 4바이트, 32비트지. 일단 첫비트는 인트처럼 부호를 나타는데 써. 이건 교수님이 알려주시겠지.
// 그리고 남은거에서 절반으로 나눠. 한 절반은 실수부분, 하나는 소수부분이 되겠지?
// 부동소수점은 2의 -1승으로, 절반씩 나누어서 이걸 합쳐서 표현해준다. 2진수 표현하듯이. 그런데 이러면 어느정도 정밀한 소수를 나타내는데 한계가 생겨.
// 0.1 + 0.1 + 0.1은 0.3이 아니라 위의 방식처럼 사용하기 때문에 0.30..001 이렇게 된다.

// C++에만 있는 자료형 - bool, boolean 오직 참과 거짓만 표현가능한 타입.
// int가 참을 가르는 법? 0빼고 나머지 전부 참
// bool은 true와 false라는 키워드로 참거짓을 정해준다.
// 그런데 출력해보면? 0과 1로 뜬다. 내부적으로는 int형이기 때문.

// bool+alpha도 설명. no+bool+alpha도 있다. 0과 1을 true false로 출력해주는걸 바꿔 줌.

// auto형 -> 자동 타입 추론. 나중가면 std::vector<std::map<std::taple<std::string, int, double>> v 이런게 나온다ㅋㅋㅋㅋㅋ
// C++ 11/14에 오면서 이걸 auto라는 키워드 한방으로 잡을 수 있다.
// => auto v; for문에서는 for (auto i = v.begin())
// 버젼 조심하자 2008은 안됨!

// 그럼 이거는 타입추론을 어떻게 할까?
// 다음의 예시를 들어주자.
// short a = 0;
// char	 b = 1;
// long  c = 2;
// 그럼 a+b+c;의 답은 뭘까? 힌트는 큰걸 작은거에 끼워 맞출수 있냐? 반대로 해야겠지.
// 답은 당연히 long이다. 작은거에 큰걸 우겨 넣을수는 없지.

// 그럼 auto는? 다음의 예시를 들어주면서 타입추론을 설명해주자.
// 근데 다른것에 비해 난이도가 높으니 상황봐서 하자. 여차하면 스킵.

// 템플릿이 들어가는 설명. 이건 여름방학이거나 진도가 어느정도 나갔다 싶을 때만 말해주자. 이제 배우는 애들한테 템플릿은 어렵다.
// int max(int a, int b){
//	return (a>b?a:b);
// }
// 다음과 같은 함수를 만들었다 치자. 그런데 롱이나 더블형이 들어오면? 일일이 만들텨?
// 이럴때 템플릿을 쓴다.
// template <typename t>
// t max(t a, t b){
//	return (a>b?a:b);
// }
// t는 자료형이 된다. 그런데,
// max(3,4.5)이렇게 정수형과 실수형이 같이오면 어떻게 될까?
// 답은 에러난다. t는 같은 자료형이기 때문에 타입 추론을 할수가 없다.
// 두개가 반드시 같은 타입이어야 추론이 된다. 아니면 다른 템플릿 하나를 더 선언해줘 보든가.

// 근데 두개를 선언했다. 이러면 리턴타입은 어느 장단에 맞춰야함?
// 이때! decltype이 힘을 발휘한다.
// auto max(t1 a, t2 b) -> devltype(a+b)
// 해석을 하자면 일단 받아서, a+b의 타입(합치면서 자동으로 큰쪽에 자료형이 되겠지)의 타입으로 리턴하겠다는 해석이다.
// 타입을 추론하기 애매할때, 이렇게 오토와 디클렛타입을 조합해서 써주자.

// 그럼 둘의 차이점은 뭘까? decltype은 표현식을, auto는 컴파일하면서 타입을 추론하는것.

// 뭘 프로그래밍 하든, 변수는 정말 많기 때문에 이런 타입추론 방법이 있다는것만 알려주자. 막 반드시 지금 기억할 필요는 없다고 해주자.

// 열거체를 설명해주자. enum. 시험에도 나왔다 이거?
// 새로운걸 배울때 가장 쉬운방법은 예시다. 그럼 열거형은 어디서 쓰이냐?
// 게임에서 상태이상 예시를 들어주자. 이걸 전부 변수로 하나하나 선언하기에는 비주얼부터 심히 안좋다.
// 열거형은 이런 어떤 카테고리, 그룹에서 쓸때 간편하다.
// 어떻게 쓰는지 설명해주자. 사용법 먼저 설명해줄지 예시부터 설명해줄지 고민해야할듯

// 그런데 열거형을 썼을대 문제가 생긴다.
// enum a { cl; } enum b { cl; }
// 이 안의 변수의 이름이 같으면, 에러를 뱉는다!
// 게다가 다른 열거체안의 변수끼리 비교가 된다. 심지어 연산도 가능하다.

// 이를 위해 scoped enum이 등장! scoped enum은 3주차에 자세히 필기 되어 있다
// enum class로 바꿔버리면, enum안의 변수들은 전역 변수로 선언이 되기 때문에 이름 중복이 처리된다.
// 그러나 class로 쓰면, class 안의 접근이 제한되기 때문에(전역범위가 아니기 때문에) 이름 중복을 넘길 수 있다.
// 이러면 열거체 끼리의 연산도 막을수가 있다. 서로 다른 클래스안(다른 자료형)으로 취급, 연산은 당연히 불가.

// 위의 상태이상 예시를 설명하고 비트연산자와 비트연산도 설명해주자. winapi에서 자주 나오는 것이므로.

// C에서의 캐스팅은 위험한편.
// 보통 형변환 한다면 너희들이 아는건, double a = (int)4.5; 이렇게 할 것이다.
// 그런데 이런걸 하다가 다음과 같은 경우는?
// char* name  = "Bill";
// void* v = (void*)name;
// int* i = (int*)v;
// 일단 에러는 안나는데, 바꿔놓고 걍 나몰라라 한다. 일단 이 예시는 주소값이 뜨긴 뜬다.
// 그런데 원래대로라면, 이런 형변환은 말도 안되는것이다.
// 아 보이드포인터 쓰지 말것. 써봤자 함수포인터 할 때나...

// C의 캐스팅은 안정성에 문제가 있다. 나몰라라하고 넘겨주는 것.

// C++은 이런 현상을 방지하기 위해 4가지의 캐스팅 방법을 준비했다.
// 자세한 내용은 2주차의 코드를 참조하자.
// static_cast		: const를 제외한 모든 명확한 타입 변환에 사용
// dynamic_cast		: 기본 타입에 대한 포인터나 참조자를 파생 타입에 대한 포인터나 참조자로 안전하게 변환, 런타임때도 사용가능
// const_cast		: const 객체를 const가 아닌 타입으로 변환
// reinterpret_cast : 비트 구성 형식을 저수준에서 재해석

// 타입은 이정도로. 그외의 가르쳐 줄때의 상황을 보고 다른것을 더 설명해 주던가 하자. 전체적인 난이도는 조금 높게 잡았다.


// 배열을 쓸때 주의해야 할점들이 많다.
// 이런걸 방지하기 위해 아예 array라는 것이 추가되었다.
// + array는 범위기반 포문을 쓸 수 있다.
// 그 외에 여러 부가기능이 많다. 안정성도 추가된것.
// 단 2차원 배열을 만들때부터 한계점이 보인다. 정말 헷갈린다!


// 범위기반 for문?
// std::vector<int> v;
// for (auto i:v){
// }
// 극단적인 예로,
// for (std::vector<std::map<std::taple<std::string, int, double>>>::const_iterator citer = v.begin() ; citer != v.cend(); ++citer)
// -> for (auto citer = v.begin();citer!= v.cend(); ++citer)
// -> for (auto citer : v) <-얘는 반복자가 된다
// 편 - 리 자바에는 for_each라는 유사한 기능이 있다.


// 가장 난감한 주제, 포인터
// 포인터는 너희들의 경계선이다. 프로그래머의 첫번째 드랍기준, 관문이 바로 포인터다.
// 포인터를 못배우면 자료구조를 못가고, 자료구조를 못가면 알고리즘을 못배운다.
// 특히 포인터는 C와 C++에 밖에 없는 규격이기 때문에 어려운게 당연하다.

// 포인터를 보기전에 메모리라는 걸 잠깐 보자.
// 다차원 배열을 접하면 메모리구조를 무슨 시트처럼 되있다 헷갈리는 애들이 점점 생기는데, 실제로는 단 한줄에 쭉 나열된거에 불과하다.
// 메모리는 그냥 저장되어있는 장소고 굳이 저렇게 시트처럼 보기 좋게 나열할 필요가 없다.
// 메모리에 대한 설명을 좀 해주자. 개인적으로 메모리 구조 좀 공부해야할듯

// 포인터의 구조는 간단하지. &가 붙는다 -> ?의 주소 값
// *이 붙는다 = 포인터 변수다. 이건 주소만 담고 있다.
// 주의할게, 선언할때 빼고 일반 변수 앞에 *을 쓰면 역참조 연산자라고 한다 이걸. ->은 참조 연산자고.

// 포인터 변수도 어딘가 다른곳에 보관된다! 그래서 이중 삼중포인터도 쓸 수 있다.

// 문제를 하나 내보자. 5지선다!
// int i = 10; // 100번지
// int* pi = &i; // 60번지
// int** ppi = &pi; // 80번지
// int*** pppi = &pi; // 40번지
// 그럼 *(*pppi)는?
// 1번 40 2번 60 3번 80 4번 100 5번 10
// 답은 60!
// **pppi = *ppi = pi;

// 그런데 포인터를 왜 써야하냐? 는 교수님이 잘 설명해주실거라 믿지만 한번 더 설명하면
// 

// 주의! 템플릿하나 오류나면 무지 많이 뜬다.

// 콜바이밸류 콜바이레퍼런스도 한번은 봐줘야한다.

// 전처리 지시자 하면서 우리를 낚았던 그 문제도 보여주자. 교수님의 두번 낚시는 안통하게 해주자.
// #define sqrt(x) ((x)*(x)), sqrt(++i) = sqrt(int x){ return x+1*x+2; }가 된다!
