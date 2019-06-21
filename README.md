# Solitaire Chess Practice

Solitaire chess 문제를 해결하는 solver를 구현할 수 있는 platform입니다. 구현한 solver를 여러 개의 testcase로 평가하여, 결과를 보여드립니다. Solitaire Chess의 규칙은 [여기](https://www.thinkfun.com/wp-content/uploads/2015/09/SolChess-3400-IN03.pdf)에서 확인하실 수 있습니다.

## Getting Started

### Installing

#### CLI

repository를 pull 또는 다운로드 받고, command line에 다음 명령어들을 칩니다. 단, cmake와 c++14 컴파일러가 우선적으로 설치되어 있어야합니다.

```bash
git pull https://github.com/shhj1998/solitaire-chess-practice.git
cd solitaire-chess-practice
cmake .
make
```

make 명령어까지 입력이 완료되면, build 폴더 아래에 tester라는 executable file이 생긴 것을 확인하실 수 있습니다. 이를 실행하시면 됩니다. 코드 수정 후, cmake .과 make 명령어를 차례대로 치시면 실행파일이 수정될 것입니다.

#### Visual Studios

- <https://docs.microsoft.com/ko-kr/cpp/build/cmake-projects-in-visual-studio?view=vs-2019> 를 참고하여, 프로젝트를 여시면 됩니다.
- 잘 안되시면 새 프로젝트를 만들고, includes/, src/ 아래에 있는 파일들을 새로 만든 프로젝트에 옮기시면 됩니다.

## Practice

처음 실행해보면 다음과 같이 결과가 나타날 것입니다.

```bash

***Start Testing!***

[TC #01] WRONG ANSWER
[TC #02] CORRECT!
[TC #03] CORRECT!
[TC #04] CORRECT!
[TC #05] CORRECT!
[TC #06] WRONG ANSWER
[TC #07] WRONG ANSWER
[TC #08] CORRECT!
[TC #09] CORRECT!
[TC #10] CORRECT!
[TC #11] WRONG ANSWER
[TC #12] WRONG ANSWER
[TC #13] CORRECT!
[TC #14] WRONG ANSWER
[TC #15] WRONG ANSWER
[TC #16] WRONG ANSWER
[TC #17] CORRECT!
[TC #18] CORRECT!
[TC #19] WRONG ANSWER
[TC #20] WRONG ANSWER

Total Result: 10 / 20
```

- 이제 20개의 testcase에 대해서 모두 정답을 맞는 것을 목표로 하시면 됩니다! 
- 코드는 src/user.cpp의 solution 함수를 구현하시면 됩니다. 
- 이외에도 debug용으로 구현한 함수들이 있으니, 필요하시면 마음대로 사용하시면 됩니다. 
- **단, user.cpp 이외의 코드는 수정하시면 안됩니다!**

## Built With

* [CMake](https://cmake.org/) - C++ Project Build Tool
