/*
  Attenzione: facendo il copia/incolla dal PDF all’IDE si perde la formattazione del testo. Per
  rendere piu’ facilmente leggibile il programma e’ opportuno formattarlo subito dopo il  trasferimento
  nell’IDE, premendo CTRL+T.

  Questo programma identifica il colore di un oggetto (rosso o verde o blu) posto davanti ad un
  sensore di tipo TCS230.
  Piu’ in dettaglio, la luce riflessa dall’oggetto viene “letta” dal sensore utilizzando, in rapida
  sequenza, diodi sensibili al colore rosso, al colore verde ed al colore blu. Il sensore trasforma
  ogni lettura in una serie di segnali digitali, la cui frequenza e’ inversamente proporzionale al
  colore dell’oggetto in esame. Arduino converte questa frequenza (rilevata tramite l’istruzione
  “pulseIn”) in un valore compreso tra 0 a 255 e poi analizza le frequenze proposte dalla “lettura”
  effettuata dalle tre differenti tipologie di diodi e tenta di interpretarle.

  Per ottenere valori stabili ed in qualche modo vicini ai reali valori RGB, i parametri di mappatura
  (ciclo di while e istruzione map delle frequenze segnalate da ogni colore) devono essere definiti
  di volta in volta, in funzione della luce ambientale e della intensita' del colore degli oggetti
  campione.

  Nella fase inziale il rpogramma esegue quindi una serie di attivita' necessarie alla definzione dei
  parametri sia in assenza di oggetti che in presenza di oggetti colorati

  Al termine della fase di inzializzazione il sistema avra' definito i parametri necessari al
  riconoscimento di ogni colore.

  Una volta stabiliti i parametri ( e cioe' i valori minimi e massimi di ogni fotorilevatore, in presna
  di colori il programma, sempre per rendere stabile e sicura l'individuazione del colore, esegue 5
  letture consecutive per ogni oggetto posto vicino al sensore ed alla fine espone
  e considera la media dei valori rilevati.
  ---------------------------------------------------------------------------------------------------------
   Warning: cut&paste from PDF to IDE loses formatting. To restore it press CTRL + T.

  This program identifies a color of an object (red or green or blue) placed near a TCS230 sensor.

  More in detail, the light reflected by object is "read" by sensor using, in rapid succession, diodes sensitive
  to red, green and blue.
  Sensor transforms each reading into a series of digital signals, whose frequency is inversely proportional to
  the color of the object . Arduino converts this frequency (detected by the "pulseIn" instruction) in a value
  between 0 and 255 and then analyzes frequencies proposed by the "reading" performed by the three different
  types of diodes, and tries to interpret them.

  To obtain stable values and close to the real RGB values, the mapping parameters ("while" cycle and "map)
  statement)  must be defined each time, depending on ambient light and color intensity of the sample objects.
  In the initial phase, program performs a series of activities for defining the parameters both in the absence
  of objects and in the presence of colored objects.

  At the end of the initialization phase, system will have defined the parameters necessary for the recognition
  of each color.

  Once the parameters have been established (and that is the minimum and maximum values reeased by each
  photodetector), program performs 5 consecutive readings for each object placed near the sensor and then
  exposes and considers the average of the values measured.

*/

#define S0 5
#define S1 4
#define S2 7
#define S3 6
#define sensore 8
int frequenza    = 0;
int freqrosso    = 0;
int freqverde    = 0;
int freqblu      = 0;
int rosso        = 0;
int blu          = 0;
int verde        = 0;
int indice       = 0;
byte tabvalori [751];    // tabella di memorizzazione delle ripetizioni delle frequenze di ogni colore;
// l'indice della tabella e' la frequenza, e le frequenze analizzate vanno da 0 a 250 per tre colori
// matrix to storing frequencies repetitions for each color; the matrix index is the frequency, and the
// analyzed frequencies go from 0 to 250, for three colors
//
float tempoiniz   = 0;   // momento di inzio calibrazione
float tempocorr  = 0;    // momento attuale
byte minaccett   = 0;    // Occorrenze minime accettabili (il 2 % del numero totale di coocrrenze)
byte minrosso    = 250;
byte maxrosso    = 0;
byte minverde    = 250;
byte maxverde    = 0;
byte minblu      = 250;
byte maxblu      = 0;
int contatore    = 0;
byte minrosson   = 250;
byte maxrosson   = 0;
byte minverden   = 250;
byte maxverden   = 0;
byte minblun     = 250;
byte maxblun     = 0;


//
//**** routine di lettura delle frequenze in uscita dal sensore ****
//
void lettura ()
{
  //********* rileva la frequenza emanata dai fotorilevatori sensibili al rosso *******************
  // ***************detects frequency emitted by red sensitive photodetectors *********************
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequenza = pulseIn(sensore, LOW);
  if (frequenza > 250)
  {
    Serial.print ("fuori scala rosso: ");
    Serial.println (frequenza);
  }
  else
    freqrosso = frequenza;
  delay (30);
  //********* rileva la frequenza emanata dai fotorilevatori sensibili al verde *******************
  //***************detects frequency emitted by green sensitive photodetectors ********************
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequenza = pulseIn(sensore, LOW);
  if (frequenza > 250)
  {
    Serial.print ("fuori scala verde: ");
    Serial.println (frequenza);
  }
  else
    freqverde = frequenza;
  delay (30);
  //********* rileva la frequenza emanata dai fotorilevatori sensibili al blu *******************
  //***************detects frequency emitted by blue sensitive photodetectors *******************
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequenza = pulseIn(sensore, LOW);
  if (frequenza > 250)
  {
    Serial.print ("fuori scala blu: ");
    Serial.println (frequenza);
  }
  else
    freqblu = frequenza;
  delay (30);
}

void setup()
{
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensore, INPUT);
  //
  // sets the sensor for output a range equal to 20% of the frequencies
  digitalWrite(S0, HIGH);   // setta il sensore (pin s0 ed s1) in modo che fornisca un segnale
  digitalWrite(S1, LOW);   // la cui frequenza sia pari al 20& della frequenza massima fornibile
  Serial.begin(9600);
  //
  // ********** fase di calibrazione sulle frequenze minime e massime **********
  // *************** calibration phase on minimum and maximum frequencies ******
  //
  // ***********  calibrazione in assenza di colori ************************************
  // *******************calibration without colors *************************************
  //
  Serial.println ("calibrazione in assenza di colori......"); // calibration without colors...
  for (indice = 1; indice < 50; indice ++)
  {
    lettura ();             // lancia la routine di lettura delle frequenze rilasciate dal sensore
    tabvalori [freqrosso * 3] = tabvalori[freqrosso * 3] + 1; // conteggia la frequenza del rosso
    tabvalori [(freqverde * 3) + 1] = tabvalori[(freqverde * 3) + 1] + 1; // conteggia la frequenza del verde
    tabvalori [(freqblu * 3) + 2] = tabvalori[(freqblu * 3) + 2] + 1; // conteggia la frequenza del blu
  }
  //
  // *************** uscito dalla fase di rilevazione, analizza i dati memorizzati ***************
  // ***********************  analyzes stored data  **********************************************
  //
  minaccett = 1;    // definisce la minima occorrenza accettabile (il 2% del numero di cicli)
  for (indice = 1; indice < 250; indice ++)  // analizza la tabella delle frequenze per individuare la
    // frequenza minima e massima rilevata dai fotorilevatori di ogni colore
  {
    if (tabvalori [indice * 3] > minaccett) // se il numero di occorrenze del rosso e' superiore al minimo accettabile
      //  if occurrences is greater than the minimum acceptable
    {
      if (indice < minrosso)
        minrosso = indice;   // memorizza la frequenza (l'indice e' la frequenza, mentre in tabella ci sono le occorrenze)
      // memorizes frequency (index is the frequency, while in the table there are occurrences)
      if (indice > maxrosso)
        maxrosso = indice;
    }
    if (tabvalori [(indice * 3) + 1] > minaccett) // se il numero di occorrenze verde e' superiore al minimo accettabile
    {
      if (indice < minverde)
        minverde = indice;    // memorizza la frequenza (l'indice e' la frequenza, mentre in tabella ci sono le occorrenze)
      if (indice > maxverde)
        maxverde = indice;
    }
    if (tabvalori [(indice * 3) + 2] > minaccett) // se il numero di occorrenze del blu e' superiore al minimo accettabile
    {
      if (indice < minblu)
        minblu = indice;     // memorizza la frequenza (l'indice e' la frequenza, mentre in tabella ci sono le occorrenze)
      if (indice > maxblu)
        maxblu = indice;
    }
  }
  Serial.println ("frequenze minime e massime:");  // minimum and maximum frequencies
  Serial.print ("rosso: ");                        // red
  Serial.print (minrosso);
  Serial.print (" ");
  Serial.println (maxrosso);
  Serial.print ("verde: ");                       // green
  Serial.print (minverde);
  Serial.print (" ");
  Serial.println (maxverde);
  Serial.print ("blu: ");                        // blue
  Serial.print (minblu);
  Serial.print (" ");
  Serial.println (maxblu);
  for (indice = 0; indice < 750; indice ++)
    tabvalori [indice] = 0;  // azzera la tabella tabvalori
  // memorizza le frequenze minime e massime in assenza di colore (aumentati o diminuiti di 2 unita)
  // memorizes  minimum and maximum frequencies in absence of color (increased or decreased by 2 units)
  minrosson = minrosso - 2;
  maxrosson = maxrosso + 2;
  minverden = minverde - 2;
  maxverden = maxverde + 2;
  minblun   = minblu - 2;
  maxblun   = maxblu + 2;
  // ripristina i valori iniziali per una nuova calibrazione - restores the initial values for a new calibration
  minrosso = 250;
  maxrosso = 0;
  minverde = 250;
  maxverde = 0;
  minblu = 250;
  maxblu = 0;
  Serial.println ("calibrazione con i colori: ");  // colors calibration:
  Serial.println ("al via hai 15 secondi per posizionare, uno dopo l'altro, gli oggetti colorati sul sensore");
  // at "via" you have 15 seconds to place, one after another, the colored objects near sensor
  delay (3000); // aspetta tre secondi, per consentire la lettura dei dati esposti
  Serial.println ("Via! Calibrazione in corso...."); // "via! calibration in progress...
  tempoiniz = millis ();
  tempocorr = millis ();
  while ((tempocorr - tempoiniz) < 15000)  // se non sono passati 15 secondi
  {
    tempocorr = millis ();    //  memorizza il momento corrente
    lettura ();               // lancia la routine di lettura delle frequenze rilasciate dal sensore
    if (((( freqrosso < minrosson) || (freqrosso > maxrosson)) && ((freqverde < minverden) || (freqverde > maxverden)) && ((freqblu > minblun) || (freqblu < maxblun))))
    { // se la lettura e' valida (se il sensore ha letto un colore) - if reading is ok (if sensor has read a color)
      tabvalori [freqrosso * 3] = tabvalori[freqrosso * 3] + 1;             // conteggia la frequenza del rosso - add 1 to red frequency occurencies
      tabvalori [(freqverde * 3) + 1] = tabvalori[(freqverde * 3) + 1] + 1; // conteggia la frequenza del verde - add 1 to green frequency occurencies
      tabvalori [(freqblu * 3) + 2] = tabvalori[(freqblu * 3) + 2] + 1;     // conteggia la frequenza del blu - add 1 to blue frequency occurencies
      contatore ++;                                                         // conta le letture valide - counts valid readings
    }
  }
  //
  // *************** uscito dalla fase di rilevazione, analizza i dati memorizzati ***************
  // ***********************  analyzes stored data  **********************************************
  //
  Serial.print ("letture valide :");  // valid readings:
  Serial.println (contatore);
  minaccett = contatore / 50; // definisce come minima occorrenza accettabile il 2% del numero di cicli
  for (indice = 1; indice < 250; indice ++)  // analizza la tabella delle frequenze per individuare la
    // frequenza minima e massima rilevata dai fotorilevatori di ogni colore
  {
    if (tabvalori [indice * 3] > minaccett) // se il numero di occorrenze del rosso e' superiore al minimo accettabile
    { //  if occurrences is greater than the minimum acceptable
      if (indice < minrosso)
        minrosso = indice;     // memorizza la frequenza (l'indice e' la frequenza, mentre in tabella sono presenti le occorrenze
      // // memorizes frequency (index is the frequency, while in the table there are occurrences)
      if (indice > maxrosso)
        maxrosso = indice;
    }
    if (tabvalori [(indice * 3) + 1] > minaccett) // se il numero di occorrenze del verde e' superiore al minimo accettabile
    {
      if (indice < minverde)
        minverde = indice;     // memorizza la frequenza (l'indice e' la frequenza, mentre in tabella sono presenti le occorrenze
      if (indice > maxverde)
        maxverde = indice;
    }
    if (tabvalori [(indice * 3) + 2] > minaccett) // se il numero di occorrenze del blu e' superiore al minimo accettabile
    {
      if (indice < minblu)
        minblu = indice;     // memorizza la frequenza (l'indice e' la frequenza, mentre in tabella sono presenti le occorrenze
      if (indice > maxblu)
        maxblu = indice;
    }
  }
  // allarga il range delle frequenze minime e massime utilizzate per individuare i colori
  // widens range for minimum and maximum frequencies used to identify each color
  if (minrosso > 3)
    minrosso = minrosso - 3;
  else
    minrosso = 0;
  if (maxrosso < 247)
    maxrosso = maxrosso + 3;
  else
    maxrosso = 250;
  if (minverde > 3)
    minverde = minverde - 3;
  else
    minverde = 0;
  if (maxverde < 247)
    maxverde = maxverde + 3;
  else
    maxverde = 250;
  if (minblu > 3)
    minblu = minblu - 3;
  else
    minblu = 0;
  if (maxrosso < 247)
    maxblu = maxblu + 3;
  else
    maxblu = 250;
  Serial.println ("frequenze minime e massime:");  // minimum and maximum frequencies for each color
  Serial.print ("rosso: ");
  Serial.print (minrosso);
  Serial.print (" ");
  Serial.println (maxrosso);
  Serial.print ("verde: ");
  Serial.print (minverde);
  Serial.print (" ");
  Serial.println (maxverde);
  Serial.print ("blu: ");
  Serial.print (minblu);
  Serial.print (" ");
  Serial.println (maxblu);
  Serial.println ("sistema pronto ad individuare i colori; poni un oggetto colorato vicino al sensore");
  // system ready; put a colored object near sensor
}
//
//
void loop()
{
  rosso = 0;
  verde = 0;
  blu = 0;
  tempoiniz = millis ();  // memorizza il momento di inizio del loop delle 5 letture
  for (indice = 1; indice < 6; indice = indice)  // esegue 5 letture  e poi utilizza la media di ogni lettura per individuare il colore
    //  performs 5 readings and then uses the average to identify color
  {
    tempocorr = millis (); // memorizza il momento della rilevazione
    if ((tempocorr - tempoiniz ) > 2000)  // se sono passati piu' di due secondi da inizio rilevazione significa che il sensore non
      // vede alcun colore e quindi azzera i dati e ricomincia il loop di lettura - if more than two seconds have elapsed since the
      // detection  beginning, it means that sensor does not see any color and therefore resets data and starts the reading loop again
    {
      indice = 1;
      tempoiniz = tempocorr;
      rosso = 0;
      verde = 0;
      blu = 0;
    }
    else     // se sta leggendo un colore - if is reading a color
    {
      lettura (); // lancia la routine di lettura dei colori
      if (((( freqrosso < minrosson) || (freqrosso > maxrosson)) && ((freqverde < minverden) || (freqverde > maxverden)) && ((freqblu > minblun) || (freqblu < maxblun))))
      { // se la lettura e' valida (se il sensore ha individuato un oggetto) - if reading i valid
        indice++;
        rosso = rosso + map(freqrosso, minrosso, maxrosso, 255, 0);  // rimappa la frequenza per conventirla in valori RGB
        verde = verde + map(freqverde, minverde, maxverde, 255, 0);  // rimappa la frequenza per conventirla in valori RGB
        blu = blu + map(freqblu, minblu, maxblu, 255, 0);            // rimappa la frequenza per conventirla in valori RGB
      }
    }
  }

  // ********** individua il colore *********
  //  ********* compute a color **************
  Serial.print("R = ");
  Serial.print (rosso / 5);
  Serial.print("  ");
  Serial.print("G = ");
  Serial.print (verde / 5);
  Serial.print("  ");
  Serial.print("B = ");
  Serial.print (blu / 5);
  Serial.print("  ");
  if ((blu > verde) && (blu > rosso))
    Serial.println ("   blu");  // blue
  if ((verde > blu) && (verde > rosso))
    Serial.println ("   verde");  // green
  if ((rosso > verde) && (rosso > blu))
    Serial.println ("   rosso");   // red
}
