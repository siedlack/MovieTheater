# MovieTheater

Dodałem do repo przykład jak, wydaje mi się, najlepiej będzie pracować nad tym projektem.

## How to

Jeżeli coś tu jest dla Was bardzo oczywiste to przepraszam ale nie wiem na jakim poziomie ogarniacie :). Pobieramy sobie repo

```
$ git clone https://github.com/siedlack/MovieTheater.git
```

Potem robimy sobie swój branch

```
$ git checkout -b [name_of_your_new_branch]
```

Możecie go nazwać jak chcecie, albo od nazwiska albo od tego co aktualnie robicie, np. ja zajmę się na początku czytaniem pliku więc mój branch może nazywać się file_parsing. Potem standardowo 
```
$ git add .
```
```
$ git commit -m "Short explanation"
```
```
$ git push origin [name_of_your_new_branch]
```
Potem się zrobi pull requesta do brancha master i będzie super.

Lekturka: https://git-scm.com/book/pl/v1/Ga%C5%82%C4%99zie-Gita-Podstawy-rozga%C5%82%C4%99ziania-i-scalania


## Hello.h i Hello.c

Mamy header hello.h i plik hello.c
W headerze mamy deklarację funkcji hello() a w pliku .c mamy definicję i tam wrzucamy to co robi funkcja.
Następnie w mainie wywołujemy już funkcję hello(). Takie coś pozwoli nam na pracowanie w oddzielnych plikach co z kolei pozwoli nam uniknąć konflików w gicie (taka sytuacja gdzie jeden plik jest zmienany lokalnie przez kilku userów i potem git nie wie która wersja pliku jest aktualna). 

## Nazewnictwo

Proponuję używać angielskiego do nazywania ogólnie wszystkiego. Komentarze do commitów mogą być po polsku, wszystko jedno. 
Ważne też żeby jednak unikać nazywania zmiennych w ten spoób:

```
int a = 15;
```

albo

```
char a[10];
```

Trzeba się później przekopywać przez kod żeby zrozumieć co robi zmienna a, chyba że jest to iterator w pętli to wtedy i, j, k itd są wystarczająco oczywiste. Np.

```
char moviesArray[10];
```

## Będzie dobrze

Jakby coś to chętnie pomogę na tyle ile ogarniam. Czy to jakieś rzeczy związane z gitem czy z C.
