# Prova intermedia di programmazione
**Autori**: Andrea Sacchetto, Elia Tolfo, Matteo Trevisan

**Gruppo**: Dignitosamente brilli

## Consegna
Progettare e implementare la classe `Book` che rappresenta un libro.
Implementare una classe `BookShelf` che gestisce vettori di elementi `Book`.
Un ulteriore file .cpp deve contenere il main, usato per i test.

## Modalità operative

Dopo una fase iniziale di analisi della struttura generale del codice e di come
volevamo fosse organizzato, ci siamo divisi i compiti.

Ogni componente del gruppo ha perciò implementato una classe e successivamente abbiamo fatto una fase di review 
in cui abbiamo letto assieme il codice degli altri per scambiarci pareri, opinioni e correggere eventuali errori.

## Strumenti utilizzati

Per gestire la compilazione è stato usato CMAKE.
Per il controllo di versione e la condivisione del codice abbiamo scelto di usare rispettivamente Git e Github.

## Compilazione ed esecuzione del progetto

Per creare i file cmake eseguire il seguente comando dalla cartella principale del progetto

`cmake .`

Procedere poi alla compilazione

`make`

ed infine eseguire il programma con

`./Prova_intermedia`


## Note su codice

- Il costruttore di `Date` se chiamato con il costruttore di default crea degli oggetti a tutti gli effetti validi (con data 1/1/1970).
  
  Per prevenire errori (e.g. Usare una data di copyright sbagliata) è messa a disposizione la funzione `has_been_set()` della classe 
  `Date` per controllare se la data è stata precedentemente impostata ad un valore voluto.

  L'uso di `BookShelf` aiuta a prevenire questo tipo di errore in quanto stampa "Not set" se la data non è impostata. 
- `Book` non implementa il move assignment operator in quanto non ha variabili membro oggetto.
- L'ISBN di default è stato impostato a "000-000-000-0"
- Nell'implementazione della classe `BookShelf` abbiamo scelto di attenerci il più possibile alla `std::vector` per cui tutte le scelte sul comportamento delle funzioni membro 
  sono da rimandare alla [documentazione della libreria standard](https://en.cppreference.com/w/cpp/container/vector)
- E' previsto l'inserimento di più libri uguali

## Miscellanea
E' stato scelto di non consegnare la cartella .git in quanto non era richiesto il suo uso per questo progetto, inoltre dato che non tutti i componenti
del gruppo avevano una passata esperienza con questo strumento la visione dei log avrebbe potuto generare delle incomprensioni che abbiamo preferito evitare.
L'esperienza fatta verrà sfruttata per il progetto finale.