//#include <iostream>
//
//using namespace std;
//
//int functions1(int a, int b) {
//	return a + b;
//}
//
//int functions3(int a, int b) {
//	return a * b;
//}
//
//int functions2(int a, int (*function)(int a, int b)) {
//	return a - function(a,a);
//}
//
//void main() {
//	cout << functions2(5, functions1) << endl;
//	cout << functions2(5, functions3) << endl;
//}
//
//// 함수 포인터의 활용 예시
//
//// public void Callback(object obj)
//// {
////
////	 if (obj == "CreateNode")
////	 {
////	 	nodes[nodeNum] = new Nodes();
//// 		nodes[nodeNum].NodeStyle = "flow node hex 4";
////		nodes[nodeNum].isEnable = true;
////		nodes[nodeNum].NodeStyle.CalcScreenSize(new Vector2(0, 0));
////		nodes[nodeNum].position = new Rect(_mousePosition.x, _mousePosition.y, 320, 80);
////		//nodes[0].NodeStyle.Draw(Nodeposition, false, false, false, false);
////
////		nodeNum++;
////
////	 }
//// }
////
//// menu.AddItem(new GUIContent("CreateNode"), false, Callback, "CreateNode");
//
//// AddItem에서 받은 함수 포인터를 이용하여 Callback 함수를 실행시키는 모습. 