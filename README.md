# Krypteringsprojekt

Jag har valt att enkryptera med metoderna, caesar cipher, 

## Kom igång

### Bygga
Skapar en fil "encrypt"
```bash
make
```
### Köra
Kör filen med ett meddelande som argument
```bash
./encrypt "meddelande"
```
Exempel output: 
```
ENCRYPTING WITH ROT13...  
ENCRYPTED msg: zrqqrynaqr  
DECRYPTED: meddelande  
  
ENCRYPTING WITH CAESAR WITH SHIFT=3  
ENCRYPTED: phgghodqgh  
DECRYPTED: meddelande  
  
Encrypting with RSA...  
Generating keys...  
Public key: (3119, 3233)  
Private key: (3119, 3233)  
Encrypted: 1661 3201 97 97 3201 928 100 676 97 3201  
Decrypted: meddelande  
  
ENCRYPTING WITH VIGNERE, KEY=MATH  
ENCRYPTED: yewkqltupe  
DECRYPTED: meddelande
```
## Struktur
Implementationerna finns i `./src/` 

## Kryptoanalys

### Caesar skiffer & ROT13
Caesar skiffret är en av de äldsta och enklaste krypteringsmetoderna som används. Det fungerar genom att förskjuta varje bokstav i meddelandet med ett visst antal positioner i alfabetet. Antalet positioner som varje bokstav förskjuts med kallas "nyckeln" för krypteringen.

Ett caesar skiffer med rotation av 13 skulle kunna se ut som följande:
- A -> N
- B -> O
- C -> P
- ...
- X -> K
- Y -> L
- Z -> M

För att avkryptera ett meddelande som har krypterats med Caesar Cipher kan man helt enkelt förskjuta varje bokstav bakåt med samma antal positioner som meddelandet var förskjutet.


Fördelar med ceasar cipher:

1.  Enkel att förstå och implementera: ceasar cipher är en av de enklaste krypteringsteknikerna att förstå och implementera. Det kräver inte mycket teknisk expertis och kan genomföras med hjälp av en enkel algoritm.
2.  Snabb att använda: Eftersom ceasar cipher inte kräver några avancerade algoritmer, är det en snabb och effektiv metod för kryptering och avkryptering.

Nackdelar med ceasar cipher:
1.  Lätt att knäcka: ceasar cipher är en mycket enkel krypteringsteknik som är lätt att knäcka. Eftersom det bara finns 25 möjliga förskjutningsvärden (förutom ingen förskjutning alls), kan en angripare prova alla dessa möjligheter för att avkoda meddelandet.
2.  Möjliggör mönsteridentifiering: Eftersom varje bokstav i klartextmeddelandet byts ut med en fast bokstav i krypterat meddelande, kan mönster identifieras i krypterad text, vilket gör det enklare för en angripare att knäcka meddelandet.
### Vigenere
Vigenere-kryptering är en krypteringsmetod som använder ett nyckelord för att skapa en kryptonyckel som används för att kryptera ett meddelande. Krypteringsprocessen sker genom att förskjuta varje bokstav i meddelandet med en bokstav i nyckeln. Den första bokstaven i nyckeln används för att kryptera den första bokstaven i meddelandet, den andra bokstaven i nyckeln används för att kryptera den andra bokstaven i meddelandet, och så vidare.

För att kryptera meddelandet väljer man först en nyckel, vanligtvis en serie av bokstäver som upprepas flera gånger. Till exempel kan nyckeln vara "ABC", och om meddelandet är "HELLO", krypteras bokstaven "H" med bokstaven "A", bokstaven "E" med bokstaven "B", bokstaven "L" med bokstaven "C", och så vidare. När hela nyckeln har använts upprepas den från början igen.

För att utföra själva krypteringen används en tabell som kallas Vigenere-tabellen. Vigenere-tabellen är en matris som består av 26 rader och 26 kolumner, där varje rad representerar ett alfabet och varje kolumn representerar en förskjutning av alfabetet. Varje cell i tabellen innehåller en bokstav som representerar resultatet av att kryptera en bokstav i nyckeln med en bokstav i meddelandet.

Fördelar med Vigenere
1. Till skillnad från ceasar skiffret använder sig vigenere av en nyckel, för att bestämma hur varje bokstav ska förskjutas. I Vigenere spelar även positionen av bokstaven roll. En bokstav kan enkrypteras till olika bokstäver vid olika positioner i meddelandet. Detta pga det är bokstaven i keywordet som bestämmer den bokstav som det enkrypterade meddelandet ska få. Det gör att det blir svårare att detektera mönster.
2. Precis som ceasar skiffret är vigenere en enkel algorithm att implementera, samtidigt som den kör snabbt till skillnad från RSA. Förr kunde soldater enkelt använda viginere för att enkryptera sina meddelanden, i och med att det är lätt att bara kolla upp vad allt ska motsvara i en tabell. 

Nackdelar med Vigenere
1. Till skillnad från RSA är den privata och publika nyckeln den samma för viginere vilket innebär att det är svårt att distrubera nycklen. Därför kan man använda exempelvis RSA som är asymmetrisk för att enkryptera nyckeln, för att sedan kunna distrubera den.
2. Krypteringsmetodens nyckel är ju av bestämd längd, och repeteras efter att den längden uppnåtts. Det innebär att om man vet om längden på nyckeln som använts kan man lista ut hur det olika bokstäverna enkrypteras för varje bokstav i nyckeln. För att lösa detta kan man välja en nyckel som är lika lång som meddelandet, vilket eliminerar all potential till att ha repetetion.
### RSA
RSA är en asymmetrisk krypteringsalgoritm som är mycket säker om den används på rätt sätt, med till räckligt stora nycklar. Det finns rekommendationer om att RSA-nycklar minst bör vara så stora som 2048-bit.  

RSA-kryptering fungerar enligt följande steg:
1.  Generera två stora primtal, p och q. (Just nu väljer endast jag endast två primtal, kmr snart en uppdatering med generering av primtal)
2.  Beräkna produkten n = p * q. 
3.  Beräkna φ(n) = (p-1) * (q-1)
4.  Välj ett heltal e sådant att 2 < e < φ(n) och e är relativt prima med φ(n). e kallas för den publika nyckeln.    
5.  Beräkna d sådant att (d * e) ≅1 mod (φ(n)) . d kallas för den privata nyckeln.  
6.  Publik nyckel (n, e) används för att kryptera meddelanden enligt formeln C = M^e mod n, där C är det krypterade meddelandet och M är meddelandet som ska krypteras.
7.  För att dekryptera meddelandet används den privata nyckeln d enligt formeln M = C^d mod n, där M är det ursprungliga meddelandet.

Fördelar med RSA
1. RSA-kryptering bygger på antagandet att det är svårt att faktorisera ett stort tal som är produkten av två primtal. Ju större primtalen är, desto svårare blir det att faktorisera produkten.
2. RSA-kryptering är asymmetrisk, vilket innebär att den publika nyckeln och den privata nyckeln inte är samma. Det innebär att den publika nyckeln kan användas av vem som helst för att enkryptera meddelanden, men för att dekryptera meddelanden behövs den privata nyckeln. Det får innebörden av det är lättare att distrubera nyckeln. 

Nackdelar med RSA
1. RSA-kryptering hanterar och gör beräkningar på mycket stora tal, till exempel är rekommendationen för nyckeln 2048bit. Det betyder att RSA-kryptering kan vara en långsam algorithm och kräver mycket beräkningskraft för att utföras.
2.  Som sagt bygger RSA-kryptering på att man använder sig av mycket stora primtal. Min egen implementation bör endast kunna hantera primtal som är av storleken 16-bit. Det innebär att n endast blir 32-bit. Det är en stor svaghet i min RSA-implementation i och med att det inte tar särskilt lång tid att primtalsfaktorisera med modern teknik så små tal. 
3. När jag väljer talet e väljer jag det högsta möjliga talet, vilket för stora p och q har innebörden att e blir enormt. Det gör att prestandan av RSA-implementationen blir förfärlig i och med att vi kommer behöva göra beräkningar på ett tal upphöjt med ett enormt tal. Även om talet inte blir i sig blir enormt. Kommer det behövas många iterationer för pow_mod funktionen.

 I och med att det krävs mycket beräkningskraft för att använda RSA-kryptering används ofta RSA tillsammans med andra krypterings metoder, som exempelvis AES. AES är en symmetrisk krypteringsmetod använder samma nyckel som publik och privat. Det innebär att man inte lätt kan distrubera nyckeln. Därför kan i stället RSA-kryptering kryptera nyckeln för att den sedan ska kunna distrubera nyckeln. RSA-kryptering som kräver beräkningskapacitet blir svår att enkryptera stora mängder data, vilket gör att man istället använder symmetriska metoder och använder RSA för att enkryptera själva nycklen.
