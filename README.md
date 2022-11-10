# POP_PROJEKT_22Z
_Richad Staszkiewicz, Andrzej Bednarczyk_

## Zadanie
_Zaimplementować i przetesotować algorytm A\* dla zadania znalezienia ścieżki o najmniejszej wadze od punktu A do B. Wejściem aplikacji jest plik z listą krawędzi grafu (dla każdej krawędzi zdefiniowany jest punkt początkowy, końcowy i waga krawędzi). Wyjściem aplikacji jest najkrótsza scieżka od punktu A do punktu B. Porównać działanie algorytmu A\* z "brutalnym" przeszukiwaniem grafu. Zastosowanie dodatkowego algorytmu będzie dodatkowym atutem przy ocenie projektu._

## Interpretacja
Mając przykładowe wejście w postaci pliku zawierającego:
1. W pierwszej linii: W (liczba wierzchołków), K (liczba krawędzi), P (liczba zapytań)
2. W następnych K liniach: S1 (nr wierzchołka początkowego), S2 (nr wierzchołka końcowego), D (odległość)
3. W następnych P liniach: S1 (nr wierzchołka początkowego), S2 (nr wierzchołka końcowego)

Przykład takiego pliku w postaci `test1` znajduje się poniżej:
```txt
3 3 1
0 1 4
1 2 6
0 2 20
0 2
```

Spodziewaną odpowiedzią programu `main.cpp` jest plik .csv zawierający P linii o formacie:
```txt
[Odległość brut], [Odległość A*], [Odległość Dijkstra], [Czas brut], [Czas A*], [Czas Dijkstra]
```

## Rozwiązanie
Zaimplementowano klasę Graph do przechowywania reprezentacji grafu.

W trakcie prac zaimplementowano następujące algorytmy:
1. A* - obsługiwany przez klasę Astar
2. Dijkstra - obsługiwany przez klasę Dijkstra
3. Brut - obsługiwany przez klasę Brut

Oprogramowanie tworzono z pomocą technik TDD na z testowaniem na podstawie biblioteki GTest. Każda z klas jest testowana w osobnym pliku i była tworzona rozdzielnie od reszty.


## Omówienie algorytmów

### Brutalny
Algorytm brutalny przeszukuje wyczerpująco zbiór rozwiązań znajdując minimalną ścieżkę. Działa w złożoności O(n^2).

### Dijkstra
Algorytm Dijkstry przeszukuje graf na podstawie ciągłego rozszerzania podobnego do BFS, gdzie kolejka jest parametryzowana odległością od wierzchołka startowego.

### A*
Algorytm A* ma idę taką samą ajk Dijkstra, ale kolejkę parametryzuje nie odległość rzeczywista wierzchołka początkowego, a jej suma z estymowaną heurystycznie odległością wierzchołek-cel. W tym konkretnym zadaniu, ponieważ graf nie leży w metryce miejskiej na potrzeby algorytmu założono że posiadamy wcześniejszzą informację o ilości krawędzi dzielących wierzchołek od celu. Wówczas funkcja heurystyczna dopuszczalna i monotoniczna przy założeniu dodatnich krawędzi sprowadza się do założenia, że na ścieżce prowadzącej do celu znajdują się tylko krawędzie o najmniejszej długości w grafie.

## Grafy testowe
### Test 1
Prosty graf w kształcie trójąta. Jedyne zapytanie prosi o najkrótszą ścieżkę pomiędzy wierzchołkami przebiegającą przez trzeci z nich.

![](raport_data/test1.png)

### Test 2
Większy graf w formie cyklu. Jedyne zapytanie prosi o drogę między sąsiednimi wierzchołkami, gdzie optymalna droga prowadzi nei przez łączącą krawędź, a przez całą resztę cyklu.

![](raport_data/test2.png)

### Test 3
Średniej wielkości graf łączący punktem artykulacji cykl z grafem o dwóch obiegach. Jeden punkt pozostaje bez połączeń. Jedyno zapytanie prosi o znalezienie drogi pomiędzy punktem w cyklu a jednym z punktów artykulacyjnych obiegów. Drugie prosi o znalezienie ścieżki z punktu wolnego do grafu.

![](raport_data/test3.png)

### Test 4
Średniej wielkości graf rozłączny skłądający się z kliki 4 wierzchołków z dołączoną krawędzią do piątego i łańcucha trzech wierzchołków. Pierwsze zapytanie prosi o znalezienie ścieżki pomiędzy kliką a łańcuchem.

![](raport_data/test4.png)

### Testy weryfikacyjne

| Graf | Ilość wierzchołków | Ilość krawędzi | Ilość zapytań | cechy |
| :---: | :---: | :---: | :---: |  :---: |
| test5 | 1 000 | 499 500 | 1 | Graf pełny |
| test6 | 10 000 | 9 999 | 1 | Ścieżka |
| test7 | 25 000 | 24 999 | 1 | Ścieżka |
| test8 | 100 | 2 442 | 1 | Graf randomizowany |
| test9 | 1 000 | 249 987 | 1 | Graf randomizowany |
| test10 | 25 000 | 3 127 883 | 1 | Graf randomizowany |
| test11 | 50 000 | 1 249 505 | 1 | Graf randomizowany |
| test12 | 1 000 | 1 000 | 1 | Cykl |

## Rezultaty

Podczas badania pominięto testy 1-4 ze względu na małą wielkość.

### Czasowe
Podczas przeprowadzania testów otrzymano następujące rezultaty czasowe:
| Graf | Ilość zapytań | A* | Dijkstra | Brut | Jednostka czasu |
| :---: | :---: | :---: | :---: | :---: | :---: |
| test1 | 1 | 1000 | 1000 | 1400 | nanosekundy |
| test2 | 1 | 1900 | 1600 | 1800 | nanosekundy |
| test3 | 1 | | | | nanosekundy |

### Ilościowe
Podczas przeprowadzania testów otrzymano następujące rezultaty ilościowe.
Rozpatrywane jest pierwsze zapytanie każdej serii.
| Graf | Optimum globalne | A* | Dijkstra | Brut |
| :---: | :---: | :---: | :---: | :---: |
| test1 | 1 | 1000 | 1000 | 1400 |
| test2 | 1 | 1900 | 1600 | 1800 |
| test3 | 1 |


## Dyskusja wyników
Rezultaty wykazują, że
## Podsumowanie

## Dokumentacja
Dokumentacja została skompilowana na podstawie komentarzy z pomocą narzędzia DoxyGen. Wskazane w raporcie wizualizacje grafów dokonano z pomocą narzędzia https://csacademy.com/app/graph_editor/.

## Licencja
MIT GNU Open Licence
