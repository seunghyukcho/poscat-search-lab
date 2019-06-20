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

make 명령어까지 입력이 완료되면, build 폴더 아래에 tester라는 executable file이 생긴 것을 확인하실 수 있습니다. 이를 실행하시면 됩니다.

#### Visual Studios

새 프로젝트를 만들고, includes/, src/ 아래에 있는 파일들을 새로 만든 프로젝트에 옮기시면 됩니다. 가능하시다면 통째로 CMake project로 여셔도 됩니다.

## Practice

처음 실행해보면 다음과 같이 결과가 나타날 것입니다.

```bash
Testcase #1: Wrong Answer...
Testcase #2: Correct!
Testcase #3: Correct!
Testcase #4: Correct!
Testcase #5: Correct!
Testcase #6: Wrong Answer...
Testcase #7: Wrong Answer...
Testcase #8: Correct!
Testcase #9: Correct!
Testcase #10: Correct!
Testcase #11: Wrong Answer...
Testcase #12: Wrong Answer...
Testcase #13: Correct!
Testcase #14: Wrong Answer...
Testcase #15: Wrong Answer...
Testcase #16: Wrong Answer...
Testcase #17: Correct!
Testcase #18: Correct!
Testcase #19: Wrong Answer...
Testcase #20: Wrong Answer...
Total Result: 10 / 20
```

- 이제 20개의 testcase에 대해서 모두 정답을 맞는 것을 목표로 하시면 됩니다! 
- 코드는 src/user.cpp의 solution 함수를 구현하시면 됩니다. 
- 이외에도 debug용으로 구현한 함수들이 있으니, 필요하시면 마음대로 사용하시면 됩니다. 
- **단, user.cpp 이외의 코드는 수정하시면 안됩니다!**

## Built With

* [CMake](https://cmake.org/) - C++ Project Build Tool
