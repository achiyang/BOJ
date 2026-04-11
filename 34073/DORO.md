## 문제

>***DORODORO WAN!***  
>— voice 군단, DORODORA ODORO  

<p align='center'>
    <img src="./DORO.png" width="387" height="400">
</p>

사람 말을 하는 귀엽고 깜찍한 생물 도로롱에 대해서 아는가? 이 생물은 사람의 말을 따라 하는 기묘한 능력을 갖추고 있지만, 안타깝게도 각 단어의 끝에 DORO를 붙이지 않고서는 말을 하지 못한다! 예를 들어, 도로롱이 **i love you**라는 말을 하고자 한다면, 실제로는 **iDORO loveDORO youDORO**라고 말을 한다.

도로롱이 전하고자 하는 말이 주어진다. 이 말은 알파벳 소문자와 공백으로만 구성되어 있다. 이 말을 토대로 실제로 도로롱이 하는 말이 무엇일지 예측해 보자!

## 입력
첫 번째 줄에 단어의 개수 
$N$이 주어진다. (
$1 \leq N \leq 100$)

두 번째 줄에 도로롱이 전하고자 하는 말이 
$N$개의 단어의 형태로 주어진다. 각 단어들은 공백 한 칸으로 구분되며, 알파벳 소문자로 구성된다. 도로롱이 전하고자 하는 말은 공백으로 시작하거나 끝나지 않으며, 모든 단어의 길이와 공백의 개수를 합치면 
$100$ 이하이다.

## 출력
도로롱이 실제로 하는 말을 출력한다.

## 예제 입력 1 
```
13
you can get badge and background if you solve at least one problem
```

## 예제 출력 1 
```
youDORO canDORO getDORO badgeDORO andDORO backgroundDORO ifDORO youDORO solveDORO atDORO leastDORO oneDORO problemDORO
```

## 예제 입력 2 
```
2
blue archive
```

## 예제 출력 2 
```
blueDORO archiveDORO
```

## 예제 입력 3 
```
3
i love you
```

## 예제 출력 3 
```
iDORO loveDORO youDORO
```
