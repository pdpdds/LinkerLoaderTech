# 링커, 로더 실전 개발 테크닉 - 실행 파일 생성을 위한 필수 기술
사카이 히로카즈님의 저서 "링커, 로더 실전 개발 테크닉"의 부록 소스코드입니다.  
한국 출간을 목표로 관련 내용을 정리하고 있습니다.

## 개요
프로그래밍을 통해 실행 파일을 만들려면 '링크' 작업이 필요하다. 또한 실행 파일을 실제로 동작시키려면 '로드' 작업이 필요하다. 또한 임베디드 시스템 개발이나 OS를 개발할 때는 메모리 재배치 같은 기능이 필수다. 더욱이 OS 커널의 소스코드에서는 링커의 기술을 구사하는 경우가 많기 때문에 링커에 대한 지식이 없으면 소스코드를 읽기가 조금 어렵다. 따라서 링커와 로더에 관한 지식이 필요하다.
이 책은 링커와 로더에 대해 실제로 연습을 해보면서 설명을 진행한다. 코어 덤프로부터 실행을 재개하거나 링커를 자작하는 것과 같은 흥미로운 실행도 보여준다.

## 목차
제1장 링커와 로더의 역할  
　1.1 링커와 오브젝트  
　1.2 링커의 임무  
　1.3 실행 형식과 섹션  
　1.4 심볼과 재배치  
　1.5 로더의 일  
　1.6 링커 스크립트  
　1.7 스타트업 루틴  

제2장 ELF 형식의 해석  
　2.1 오브젝트 포맷  
　2.2 ELF 형식의 구조  
　2.3 사용할 샘플 프로그램  
　2.4 ELF 헤더  
　2.5 ABI(Application Binary Interface)  
　2.6 섹션 이름의 의미  
　2.7 섹션 헤더  
　2.8 프로그램 헤더  
　2.9 심볼 테이블  
　2.10 재배치 테이블    
   2.11 ELF 파일의 해석 예  

제3장 라이브러리 아카이브의 해석  
　3.1 라이브러리 아카이브란  
　3.2 라이브러리 아카이브 구조  
　3.3 아카이브의 해석 예  
　3.4 라이브러리 아카이브의 해석  
　3.5 라이브러리 아카이브 링크  
　칼럼 두 개의 아카이브 포맷이 혼재된 경우  
　칼럼 checksym 사용법  
 
 제4장 실험 -- 링커로 놀아보자  
　4.1 배열과 포인터의 차이  
　4)2 const 변수에 기록해 보기  
　4.3 글로벌 변수를 static으로 만들자  
　4.4 심볼의 이름을 변경해 보자  
　4.5 변수의 은닉을 계층화하자  
　4.6 정적 변수를 다시 초기화하자  
　4.7 자동 초기화를 수행  
　4.8 종료 시 함수를 호출하자  

제5장 링커 스크립트의 역할과 동작  
　5.1 링커와 로더의 역할  
　5.2 링커  스크립트 역할  

제6장 링커 스크립트를 사용한 실험  
　6.1 표준 링커 스크립트  
　6.2 링커  스크립트 실험  

제7장 커맨드 라인 지정에 따른 동작의 차이와 링커의 이용법  
　7.1 커맨드 라인 지정의 차이에 따른 동작의 차이  
　7.2 커맨드 라인에 의한 차이를 실험으로 확인하자  
　7.3 중복 심볼 문제의 설명과 해결책  
　7.4 링커 이용의 실제 예 -- 바이너리 데이터를 삽입하자  
　칼럼 및 기타 링커 이용방법  

제8장 로더의 원리와 간이 로더 작성  
　8.1 로더의 필요성  
　8.2 로더 개요  
　8.3 간이 로더의 원리  
　8.4 간이  로더 작성  
　8.5 샘플 프로그램  
　8.6 간이 로더 실행  

제9장 코어 덤프의 해석  
　9.1 코어 덤프란 무엇인가  
　9.2 코어 덤프 세부사항  
　9.3 중단된 프로세스 재개  
　9.4 중단과 재개 실험  
　칼럼 setjmp()와 longjmp()  

제10장 간이 링커의 작성  
　10.1 오브젝트 파일과 링커 개요  
　10.2 심볼 해결의 실제  
　10.3 샘플 프로그램  
　10.4 링커 작성  

제11장 공유 라이브러리 사용법  
　11.1 가상 메모리  
　11.2 위치 독립 코드  
　11.3 라이브러리 만들기 및 설치  
　11.4 공유 라이브러리의 내부 구조  
　11.5 동적 링커  
　11.6 동적 라이브러리 로드  

## 부록
* [소스코드 설명](docs.md)
 
## 빌드
WSL2 우분투 20.04 LTS에서 정상적으로 빌드됨을 확인하였습니다.

## 레퍼런스
* [서적링크](http://kozos.jp/books/linker_book.html)  
* [서적 링커,로더 실전개발 테크닉 발매기념 인터뷰](http://www.kumikomi.net/archives/2010/08/post_28.php)



