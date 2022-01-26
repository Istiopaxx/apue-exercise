# APUE_Exercises
Advanced Programming in UNIX Envrionment Exercises

## How to Exercise?

[APUE 3판](http://www.apuebook.com/apue3e.html) 저자는 책에서 필요한 함수와 값들을 모두 가지고 있는 `apue.h` 헤더 파일을 제공합니다.
이와 함께 책에서 쓰인 소스코드를 제공하니, 이를 다운받아서 실습환경을 구성하면 됩니다.

`gcc` 컴파일러가 설치되어있고 `$PATH`에 등록되어 있어야 합니다.

1. 먼저 /apue.3e/lib 에서 `make all` 실행

2. 루트에서 
    ```bash
    source env.sh
    ```
    실행 후

3. 원하는 소스 파일을
    ```bash
    buildone <filename>
    ```
    명령어를 실행하여 컴파일합니다.

## 교재

![APUE_3ed](http://www.apuebook.com/cover3.jpg)

[Advanced Programming in the UNIX® Environment, Third Edition](http://www.apuebook.com/etc3e.html)
