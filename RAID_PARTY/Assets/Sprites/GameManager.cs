using UnityEngine;
using System.Collections;

public class GameManager : MonoBehaviour {

    private bool GameStart;
    private bool BossDead;
    private bool inputOn;
    private bool TimeCheck;

    private int MyTurn;
    private int GameTurn;
    private int GoNum;
    private int MyCommand;
    private int[] Command = new int[5];

    private int[] Nums = new int[5]; // 순번

    private MyCharInfo[] Charcters = new MyCharInfo[4];

    public GameObject[] GameObjects = new GameObject[6];
    public GameObject[] PartyPosition = new GameObject[4];

    // Use this for initialization
    void Start () {
        GameStart = false;
        inputOn = false;    
        MyTurn = 0;
        GoNum = 0;

        // 서버에서 해야할것
        // - 보스 패턴 정하기, 랜덤
        // - 순번 정해주기, 지금은 랜덤
        // - 일시적으로 능력치가 상승했을때 보스의 패턴이 끝난 이후 원래대로 돌림

        // 서버에서 캐릭터 정보를 불러옴
        // 캐릭터 정보를 토대로 순번을 정한후 MyTurn에 자신의 순번 저장
        // 순번 열은 Nums에 저장
        // 다른 캐릭터 정보들은 Charcter[]에 저장


    }

    // Update is called once per frame
    void Update () {

        // 누가 선택을 하고 있는지 서버로 부터 받아온후 GoNum에 저장
        switch (GoNum) // 화살표로 선택중인 사람 표시
        {
            case 1: GameObjects[5].transform.position = new Vector3(GameObjects[0].transform.position.x, 1.6f ,0); break;
            case 2: GameObjects[5].transform.position = new Vector3(GameObjects[1].transform.position.x, 1.6f, 0); break;
            case 3: GameObjects[5].transform.position = new Vector3(GameObjects[2].transform.position.x, 1.6f, 0); break;
            case 4: GameObjects[5].transform.position = new Vector3(GameObjects[3].transform.position.x, 1.6f, 0); break;
        }

        // 다른 플레이어들은 어떤 선택을 했는지 커맨드에 저장

        // 보스가 죽었는지 살았는지 서버로 부터 받아옴

        if (BossDead)
        {
            // 보상 화면
        }

        if (GoNum == MyTurn) // 자신의 순번이 되면 커맨드를 정하게 함
        {
            inputOn = true;
            TimeCheck = true;
            if (!TimeCheck)
            {
                StartCoroutine("TimeOut");
            }

            // 서버로 MyCommand를 송출
            if (MyCommand != 0 && !TimeCheck)
            {
                GoNum++; 
                // 다음 차례를 서버로 송출
            }

            
        }

        // 보스의 커맨드는 서버에서 받아옴
        if (GoNum == 5)
        {
            
        }

        if (GoNum == 6) // 모든 플레이어가 명령을 했을 경우 액션 실행
        {
            ActionStart();
        }

	}

    IEnumerator TimeOut()
    {
        yield return new WaitForSeconds(10.0f);
        TimeCheck = false;
    }

    void ActionStart()
    {
        // 커맨드 별로 액션 실행
        for (int i = 0; i < 4; i++)
        {
            if (i < 4)
            {
                switch (Charcters[Nums[i]-1].jobCode)
                {
                    case 1:
                        switch (Command[i])
                        {
                            case 0: break; // 스킵
                            case 1:
                                if (Nums[i] - 2 < 0)
                                {
                                }
                                else
                                {
                                    GameObjects[Nums[i] - 1].transform.position = new Vector3(PartyPosition[Nums[i] - 2].transform.position.x, -0.5f, 0);
                                    GameObjects[Nums[i] - 2].transform.position = new Vector3(PartyPosition[Nums[i] - 1].transform.position.x, -0.5f, 0);
                                    MyCharInfo tmp = GameObjects[Nums[i] - 1].GetComponent<MyCharInfo>();
                                    Charcters[Nums[i] - 2] = Charcters[Nums[i] - 1];
                                    Charcters[Nums[i] - 1] = tmp;
                                }
                                break; // 딜러 좌로 이동
                            case 2:
                                if (Nums[i] >= 4)
                                {
                                }
                                else
                                {
                                    GameObjects[Nums[i] - 1].transform.position = new Vector3(PartyPosition[Nums[i]].transform.position.x, -0.5f, 0);
                                    GameObjects[Nums[i]].transform.position = new Vector3(PartyPosition[Nums[i] - 1].transform.position.x, -0.5f, 0);
                                    MyCharInfo tmp = GameObjects[Nums[i] - 1].GetComponent<MyCharInfo>();
                                    Charcters[Nums[i]] = Charcters[Nums[i] - 1];
                                    Charcters[Nums[i] - 1] = tmp;
                                }
                                break; // 딜러 우로 이동
                            case 3:
                                // 서버에 보스 HP감소 함수를 발동시키도록 보냄
                                break; // 딜러 공격 행동
                            case 4:
                                // 서버에 보스 HP감소 함수를 발동시키도록 보냄
                                break; // 딜러 스킬 사용
                        }
                        break;
                    case 2:
                        switch (Command[i])
                        {
                            case 0: break; // 스킵
                            case 1:
                                if (Nums[i] - 2 < 0)
                                {
                                }
                                else
                                {
                                    GameObjects[Nums[i] - 1].transform.position = new Vector3(PartyPosition[Nums[i] - 2].transform.position.x, -0.5f, 0);
                                    GameObjects[Nums[i] - 2].transform.position = new Vector3(PartyPosition[Nums[i] - 1].transform.position.x, -0.5f, 0);
                                    MyCharInfo tmp = GameObjects[Nums[i] - 1].GetComponent<MyCharInfo>();
                                    Charcters[Nums[i] - 2] = Charcters[Nums[i] - 1];
                                    Charcters[Nums[i] - 1] = tmp;
                                }
                                break; // 딜러 좌로 이동
                            case 2:
                                if (Nums[i] >= 4)
                                {
                                }
                                else
                                {
                                    GameObjects[Nums[i] - 1].transform.position = new Vector3(PartyPosition[Nums[i]].transform.position.x, -0.5f, 0);
                                    GameObjects[Nums[i]].transform.position = new Vector3(PartyPosition[Nums[i] - 1].transform.position.x, -0.5f, 0);
                                    MyCharInfo tmp = GameObjects[Nums[i] - 1].GetComponent<MyCharInfo>();
                                    Charcters[Nums[i]] = Charcters[Nums[i] - 1];
                                    Charcters[Nums[i] - 1] = tmp;
                                }
                                break; // 딜러 우로 이동
                            case 3:
                                // 서버에 보스 HP감소 함수를 발동시키도록 보냄
                                break; // 딜러 공격 행동
                            case 4:
                                // 서버에 다른 아군의 체력을 회복시키도록 보냄
                                break; // 힐러 스킬 사용
                        }
                        break;
                    case 3:
                        switch (Command[i])
                        {
                            case 0: break; // 스킵
                            case 1:
                                if (Nums[i] - 2 < 0)
                                {
                                }
                                else
                                {
                                    GameObjects[Nums[i] - 1].transform.position = new Vector3(PartyPosition[Nums[i] - 2].transform.position.x, -0.5f, 0);
                                    GameObjects[Nums[i] - 2].transform.position = new Vector3(PartyPosition[Nums[i] - 1].transform.position.x, -0.5f, 0);
                                    MyCharInfo tmp = GameObjects[Nums[i] - 1].GetComponent<MyCharInfo>();
                                    Charcters[Nums[i] - 2] = Charcters[Nums[i] - 1];
                                    Charcters[Nums[i] - 1] = tmp;
                                }
                                break; // 딜러 좌로 이동
                            case 2:
                                if (Nums[i] >= 4)
                                {
                                }
                                else
                                {
                                    GameObjects[Nums[i] - 1].transform.position = new Vector3(PartyPosition[Nums[i]].transform.position.x, -0.5f, 0);
                                    GameObjects[Nums[i]].transform.position = new Vector3(PartyPosition[Nums[i] - 1].transform.position.x, -0.5f, 0);
                                    MyCharInfo tmp = GameObjects[Nums[i] - 1].GetComponent<MyCharInfo>();
                                    Charcters[Nums[i]] = Charcters[Nums[i] - 1];
                                    Charcters[Nums[i] - 1] = tmp;
                                }
                                break; // 딜러 우로 이동
                            case 3:
                                // 서버에 보스 HP감소 함수를 발동시키도록 보냄
                                break; // 딜러 공격 행동
                            case 4:
                                // 일시적으로 방어력 크게 상승
                                break; // 탱커 스킬 사용
                        }
                        break;
                }
            }
        }

        switch (Command[4])
        {
            case 1:
                // 서버로부터 보스가 어느 곳을 때렸는지 받아옴
                break;
            case 2:
                // 서버로부터 보스가 어느 곳을 때렸는지 받아옴
                break;
            case 3:
                // 보스 체력회복 이펙트 뜸, 서버안에서는 보스가 체력을 회복
                break;
            case 4:
                // 일시적으로 보스의 방어력 상승
                break;
        }

        GoNum = 1;
    }

    void getCommand(int c)
    {
        if (inputOn)
        {
            MyCommand = c;
        }
    }

    
}
