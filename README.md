# Krypteringsprojekt

Jag har valt att enkryptera med metoderna, caesar cipher, 

## Kom igång

### Bygga
// Creates a file "encrypt"
```bash
make
```
### Köra
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
    
3.  Möjliggör mönsteridentifiering: Eftersom varje bokstav i klartextmeddelandet byts ut med en fast bokstav i krypterat meddelande, kan mönster identifieras i krypterad text, vilket gör det enklare för en angripare att knäcka meddelandet.
### Vigenere

### RSA
