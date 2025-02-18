## Parcel Warehouse

This project implements algorithms for optimizing **parcel placement in a 2D warehouse space**. The warehouse consists of different field types, and **parcels are categorized as regular, priority, or heavy**, each with specific placement rules. The Logistics class manages parcel distribution using a strategy pattern, allowing different **algorithms like RandomPlacement, TightPlacement, and EasyAccessPlacement**. The Storage class represents the warehouse, **handling parcel placement and retrieval**. Future expansions include 3D space support, new parcel types, and additional placement strategies.

![Alt text](parcel_warehouse.jpg)

--------------------------------------------------------------------------------------------------------------------------------------------------
**This group project was created for the Objective Programming course during my second semester at WUT.**

## Magazyn

W naszym projekcie zajmiemy się implementacją kilku algorytmów, które według danych kryteriów pozwolą w najlepszy sposób ułożyć paczki w magazynie. 

W naszym projekcie poczyniliśmy kilka założeń:  
- Magazyn i paczki opisywane są w przestrzeni dwuwymiarowej.  
- Platforma składa się z pól, a jej wymiary opisywane są w ilości tych pól
(np. 20 pól na 50 pól, otrzymujemy w ten sposób abstrakcję na dowolną jednostkę miary, 1 pole może mieć 1cm lub 10m)
- Istnieją różne rodzaje paczek  
- Istnieją różne strategie rozkładania paczek  
- Przestrzeń magazynowa składa się z różnych rodzajów pól  

Class Logistics zajmuje się implementacją algorytmów rozkładających dostawy paczek na powierzchni magazynowej. Zastosowanie wzorca projektowego strategii pozwala na dodawanie dowolnej ilości nowych algorytmów rozkładania paczek bez ingerencji w resztę kodu projektu. Klasa Logistics zawiera kontekst potrzebny klasom implementującym strategie rozkładania paczek a klasy EasyAccessPlacement, RandomPlacement i TightPlacement oferują różne implementacje algorytmu. Sama klasa przyjmuje wskaźnik do Storage_unit który wypełniany będzie paczkami z Delivery. 

## Algorytmy logistyczne
RandomPlacement - rozkłada paczki losowo  
TightPlacement - minimalizuje ilość miejsca zajmowanego przez dostawę  
EasyAccessPlacement - rozkłada paczki w sposób możliwie ułatwiający potencjalne ich rozpakowywanie

## Platforma

Klasa Storage_unit reprezentuje przestrzeń magazynową na paczki. Składa się z różnych rodzajów pó oraz, paczki mogą być dodawane i zabierane z pól. Implementuje metody potrzebne algorytmom rozkładania paczek do pracy oraz posiada metody pozwalające na prostą wizualizację i pracę z plikami wynikowymi.

## Paczki 
Paczki, które mają zostać ułożone w magazynie trafiają tam w postaci dostawy. W tym celu stworzyliśmy klasę Delivery zawierającą kolekcję paczek.   
Paczki dzielą się na:
- paczkę zwykłą  
- paczkę priorytetową  
- paczkę ciężką  
Zarówno paczka priorytetowa jak i ciężką posiadają wszystkie cechy paczki zwykłej. Dodatkowo paczka priorytetowa musi zostać umieszczona na krańcach magazynu by umożliwić szybki dostęp do niej. Paczka ciężka natomiast musi znaleźć się na specjalnym polu przeznaczonym dla paczek ciężkich.

## Class Delivery
Klasa Delivery przyjmuje w konstruktorze kolekcję paczek. Jest to zbiór wszystkich paczek, które będą musiały zostać umieszczone w magazynie. Posiada metody pozwalające dodać paczkę do dostawy, wyjąć pierwszą dostępną paczkę oraz wyjąć określoną paczkę z dostawy.
 
## Class Package
Jest to klasa bazowa paczki zwykłej. W konstruktorze przyjmuje jej wymiary: długość i szerokość. Posiada gettery, settery, metodę wypisującą informacje na jej temat zaimplementowaną w postaci funkcji wirtualnej oraz metodę z przeciążonym operatorem == służącym do sprawdzenia identyczności paczek.

## Class PriorityPackage
Jest to klasa dziedzicząca po klasie Package. Opisuje ona paczki priorytetowe, posiadające wszystkie właściwości paczki zwykłej, ale które muszą być tak umieszczone na platformie, by można je było wyjąć jako pierwsze.

## Class HavyPackage
Jest to klasa dziedzicząca po klasie Package. Opisuje ona paczki ciężkie, które mogę stać jedynie w ściśle wyznaczonych miejscach - na polach przeznaczonych do przechowywania ciężkich paczek. Oprócz długości i szerokości klasa ta przyjmuje w konstruktorze jeszcze wagę paczki. 

## Wczytywanie i zapisywanie danych do plików
Z pliku wczytywane będą informacje o paczkach znajdujących się w dostawach.
Do pliku zapisywane będzie stan przestrzeni magazynowej po rozładowaniu dostawy.


## Rozwinięcie projektu:
- Zaimplementowanie podobnego rozwiązania dla przestrzeni trójwymiarowej 
- Nowe rodzaje paczek, pól magazynu lub strategie rozkładania
- Wczytywanie aktualnego stanu przestrzeni magazynowej z pliku przed przeprowadzeniem dostawy
