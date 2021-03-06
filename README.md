# 2021_SW_FAIR

![image](https://user-images.githubusercontent.com/34888425/143032668-c7060f32-f6ea-4c57-8667-0d0861b9e215.png)

## 주제 : 헬멧 착용감지 킥보드
최근 킥보드 이용자가 늘고 그에따라 킥보드 사고건수도 증가하면서 헬멧 착용은 킥보드를 탈때에 있어서 헬멧착용은 법적으로나 윤리적으로나 필수가 되어가는 추세이다.\
도입이 어려울 것으로 예상되었던 공용킥보드의 공용헬멧또한 추가되고 있다.\
하지만 여전히 헬멧없이 킥보드를 타는 사람이 압도적으로 많은것이 사실이다.\
해서 헬멧을 착용하지 않으면 킥보드의 전원이 켜지지 않는 그러한 시스템을 구현해보려 한다.

## 설계

##### 헬멧
![image](https://user-images.githubusercontent.com/34888425/142860403-a5cf80b8-46f5-496c-b282-1fbc8f2b2701.png)\
<img src="https://user-images.githubusercontent.com/34888425/142861585-7a379730-0f55-4ecf-a299-fb7b952959b0.png" width="50%" height="50%"> \
헬멧부는 IR센서를 헬멧내부 양쪽에 위치하여 정기적으로 IR신호를 통해 헬멧 내부에 사용자의 머리가 들어왔는지 확인하여 킥보드에 전달해준다.


##### 킥보드
![image](https://user-images.githubusercontent.com/34888425/142860696-d33f8e5b-65a0-4c8e-93b5-ca109a533b8b.png)\
킥보드는 배터리와 컨트롤러 사이의 전원을 직접적으로 차단하는 방법을 사용하므로서 소프트웨어 업데이트로 헬멧 착용 여부를 바이패스 할 수 없게 만들어준다.

## 작동영상
https://youtu.be/SEfEn80d1pw

## 오픈소스 활용

회로는 직접 설계하고 제작하였으나\
코드는 안정성을 위해 오픈소스를 적극 활용하였음.\
https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=hcheong&logNo=221109714818 \
위 오픈소스 코드의 통신부를 활용하였으며 센서활용부를 추가하여 사용함.
