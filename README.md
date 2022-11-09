# POP_PROJEKT_22Z
_Richad Staszkiewicz, Andrzej Bednarczyk_

## Zadanie
Zaimplementować i przetesotować algorytm A\* dla zadania znalezienia ścieżki o najmniejszej wadze od punktu A do B. Wejściem aplikacji jest plik z listą krawędzi grafu (dla każdej krawędzi zdefiniowany jest punkt początkowy, końcowy i waga krawędzi). Wyjściem aplikacji jest najkrótsza scieżka od punktu A do punktu B. Porównać działanie algorytmu A\* z "brutalnym" przeszukiwaniem grafu. Zastosowanie dodatkowego algorytmu będzie dodatkowym atutem przy ocenie projektu.

## Interpretacja
Mając przykładowe wejście w postaci pliku zawierającego:
1. W pierwszej linii: W (liczba wierzchołków), K (liczba krawędzi), P (liczba zapytań)
2. W następnych K liniach: S1 (nr wierzchołka początkowego), S2 (nr wierzchołka końcowego), D (odległość)
3. W następnych P liniach: S1 (nr wierzchołka początkowego), S2 (nr wierzchołka końcowego)

Przykład takiego pliku i konstruowanego przezeń grafu znajduje się poniżej:
![]("raport_data/test_graph.png")
```txt
3 3 1
1 2 4
2 3 6
1 3 20
1 3
```

Spodziewaną odpowiedzią programu `main.cpp` jest plik .csv zawierający P linii o formacie:
```txt
[Odległość brut], [Odległość A*], [Odległość Dijkstra], [Czas brut], [Czas A*], [Czas Dijkstra]
```

## Rozwiązanie
W trkcie algorytmu zaimplementowano następujące algorytmy


## Licencja
MIT GNU Open Licence
