# ISAFirmware
Biblioteka komunikacji z peryferiami płyty edukacyjnej z Arduino Due, wersja 1

# Instalacja
Biblioteki do obsługi sprzętu na płytce edukacyjnej z Arduino można zainstalować na dwa sposoby - za pomocą GITa oraz pobierając archiwum ZIP. W obu przypadkach należy wcześniej uruchomić środowisku Arduino IDE **przynajmniej raz**.

###### Instalacja repozytorium GITa
W przypadku systemów Linux należy przejść do poniższego katalogu, znajdującego się w domyślnym katalogu użytkownika:
```
cd ~/Arduino/libraries
```
W przypadku systemów Windows będzie to katalog **Moje dokumenty** (lub **My Documents** w wersji angielskiej). Następnie należy wydać poniższe polecenia:
```
git init .
git remote add origin https://github.com/InteligentneSystemyAutonomiczneIIS/ISAFirmware.git
git pull origin master
```
Pozwalają one umieścić repozytorium **ISAFirmware** bezpośrednio w ścieżce przeszukiwania środowiska Arduino IDE, ignorując istniejące już biblioteki.
Jeśli jednak w katalogu *~/Arduino/libraries/* jest pusto, można swobodnie wydać następujące polecenie:
```
git clone https://github.com/InteligentneSystemyAutonomiczneIIS/ISAFirmware.git
```

###### Instalacja z archiwum ZIP
Należy pobrać następujące archiwum:

```
https://github.com/InteligentneSystemyAutonomiczneIIS/ISAFirmware/archive/master.zip
```
i rozpakować je do katalogu *~/Arduino/libraries/*

