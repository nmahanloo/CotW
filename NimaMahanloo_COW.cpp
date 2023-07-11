// NimaMahanloo_COW.CPP
// Nima Mahanloo
// CISP 400 - HW 7
// FLC - Professor Fowler
#include <iostream>
#include <random>
#include <ctime>
#include <list>
#include <cstring>
#include <iomanip>
#include <cassert>
using namespace std;
///Feature 1 : Card Class and it's return value
// Class Card for game's card set and all task about that
class Card
{
    public:
        // Friend with class Person
        friend class Person;
        int takeACard();
        int playedCards(){return cards.size();}
        int highestPlayed();
        int reducer();
        int reducer(int);
        int cardEquality();
        int cardEquality(int);
        char* cardSurface();
        char* cardSurface(int);
        list <int> cards;
        int cardNum;
        int cardValue;
        string cardFace;
};
/// An integer function to return card value to saloon class
int Card::takeACard()
{
    cardNum = -1;
    bool cardGenerate = true;
    while ((cardGenerate == true) && (cards.size() < 52))
    {
        cardNum = rand() %52 + 1;
        cardGenerate = false;
        list <int>::iterator start;
        for (start = cards.begin(); start != cards.end(); start++)
        {
            if (*start == cardNum)
                cardGenerate = true;
        }
    }
    if (cardNum > 0)
        cards.push_back(cardNum);
    return cardNum;
}
// A dynamic character array function to Card value analyze and convert that to user friendly card format
char* Card::cardSurface ()
{
    char* number = (char*)malloc(sizeof(char));
    char* surface = (char*)malloc(sizeof(char));
    char* cardView = new char [15];
    if ((cardNum == 1) || (cardNum == 11) || (cardNum == 21) || (cardNum == 31))
    {
        number = "A";
    }
    else if (cardNum > 40)
    {
        if ((cardNum == 41) || (cardNum == 44) || (cardNum == 47) || (cardNum == 50))
        {
            number = "Soldier";
        }
        else if  ((cardNum == 42) || (cardNum == 45) || (cardNum == 48) || (cardNum == 51))
        {
            number = "Queen";
        }
        else if  ((cardNum == 43) || (cardNum == 46) || (cardNum == 49) || (cardNum == 52))
        {
            number = "King";
        }
    }
    else
    {
        if ((cardNum == 10) || (cardNum == 20) || (cardNum == 30) || (cardNum == 40))
        {
            number = "10";
        }
        else
        {
            number[0] = char((cardNum % 10)+48);
            number[1] = '\0';
        }
    }
    if (((cardNum > 0) && (cardNum < 11)) || ((cardNum > 40) && (cardNum < 44)))
    {
        surface = "Clubs ";
    }
    else if (((cardNum > 10) && (cardNum < 21)) || ((cardNum > 43) && (cardNum < 47)))
    {
        surface = "Diamonds ";
    }
    else if (((cardNum > 20) && (cardNum < 31)) || ((cardNum > 46) && (cardNum < 50)))
    {
        surface = "Spades ";
    }
    else if (((cardNum > 30) && (cardNum < 41)) || ((cardNum > 49) && (cardNum < 53)))
    {
        surface = "Hearts ";
    }
    strcpy(cardView, surface);
    strcat(cardView, number);
    return cardView;
}
// An overloaded dynamic character array function to Card value analyze and convert that to user friendly card format
char* Card::cardSurface (int cardNum)
{
    char* number = (char*)malloc(sizeof(char));
    char* surface = (char*)malloc(sizeof(char));
    char* cardView = new char [15];
    if ((cardNum == 1) || (cardNum == 11) || (cardNum == 21) || (cardNum == 31))
    {
        number = "A";
    }
    else if (cardNum > 40)
    {
        if ((cardNum == 41) || (cardNum == 44) || (cardNum == 47) || (cardNum == 50))
        {
            number = "Soldier";
        }
        else if  ((cardNum == 42) || (cardNum == 45) || (cardNum == 48) || (cardNum == 51))
        {
            number = "Queen";
        }
        else if  ((cardNum == 43) || (cardNum == 46) || (cardNum == 49) || (cardNum == 52))
        {
            number = "King";
        }
    }
    else
    {
        if ((cardNum == 10) || (cardNum == 20) || (cardNum == 30) || (cardNum == 40))
        {
            number = "10";
        }
        else
        {
            number[0] = char((cardNum % 10)+48);
            number[1] = '\0';
        }
    }
    if (((cardNum > 0) && (cardNum < 11)) || ((cardNum > 40) && (cardNum < 44)))
    {
        surface = "Clubs ";
    }
    else if (((cardNum > 10) && (cardNum < 21)) || ((cardNum > 43) && (cardNum < 47)))
    {
        surface = "Diamonds ";
    }
    else if (((cardNum > 20) && (cardNum < 31)) || ((cardNum > 46) && (cardNum < 50)))
    {
        surface = "Spades ";
    }
    else if (((cardNum > 30) && (cardNum < 41)) || ((cardNum > 49) && (cardNum < 53)))
    {
        surface = "Hearts ";
    }
    strcpy(cardView, surface);
    strcat(cardView, number);
    return cardView;
}
/// Problem Paragraph 3 : An integer function to reduce current card value by 5 because user drinking
int Card::reducer()
{
    cardNum = cards.back();
    if ((cardNum == 1) || (cardNum == 11) || (cardNum == 21) || (cardNum == 31))
        cardNum = (cardNum + 10) - 5;
    else if (cardNum > 40)
    {
        if ((cardNum > 40) && (cardNum < 44))
            cardNum -= 35;
        else if ((cardNum > 43) && (cardNum < 47))
            cardNum -= 28;
        else if ((cardNum > 46) && (cardNum < 50))
            cardNum -= 21;
        else
            cardNum -= 14;
    }
    else
    {
        if ((cardNum > 1) && (cardNum < 11))
        {
            cardNum -= 5;
            if (cardNum < 2)
                cardNum = 2;
        }
        else if ((cardNum > 11) && (cardNum< 21))
        {
            cardNum -= 5;
            if (cardNum < 12)
                cardNum = 12;
        }
        else if ((cardNum > 21) && (cardNum < 31))
        {
            cardNum -= 5;
            if (cardNum < 22)
                cardNum = 22;
        }
        else if ((cardNum > 31) && (cardNum < 41))
        {
            cardNum -= 5;
            if (cardNum < 32)
                cardNum = 32;
        }
    }
    return cardNum;
}
// Problem 3 : An overloaded integer function to reduce current card value by 5 because user drinking
int Card::reducer(int inputCard)
{
    if ((inputCard == 1) || (inputCard == 11) || (inputCard == 21) || (inputCard == 31))
        inputCard = (inputCard + 10) - 5;
    else if (inputCard > 40)
    {
        if ((inputCard > 40) && (inputCard < 44))
            inputCard -= 35;
        else if ((inputCard > 43) && (inputCard < 47))
            inputCard -= 28;
        else if ((inputCard > 46) && (inputCard < 50))
            inputCard -= 21;
        else
            inputCard -= 14;
    }
    else
    {
        if ((inputCard > 1) && (inputCard < 11))
        {
            inputCard -= 5;
            if (inputCard < 2)
                inputCard = 2;
        }
        else if ((inputCard > 11) && (inputCard < 21))
        {
            inputCard -= 5;
            if (inputCard < 12)
                inputCard = 12;
        }
        else if ((inputCard > 21) && (inputCard < 31))
        {
            inputCard -= 5;
            if (inputCard < 22)
                inputCard = 22;
        }
        else if ((inputCard > 31) && (inputCard < 41))
        {
            inputCard -= 5;
            if (inputCard < 32)
                inputCard = 32;
        }
    }
    return inputCard;
}
///Problem Paragraph 5 : A function to return highest card value witch played until now for CardSharp mode as cheating
int Card::highestPlayed()
{
    int maxCard = 0;
    list<int>::iterator start;
    list<int>::iterator stop;
    for (start = cards.begin(), stop = cards.end(); start != stop; start++)
    {
        if (*start == 1 || *start == 11 || *start == 21 || *start == 31)
            maxCard = *start;
        else if (maxCard != 1 && maxCard != 11 && maxCard != 21 && maxCard != 31)
        {
            if ((*start > 40) && (maxCard < 41))
                maxCard = *start;
            else if ((maxCard > 40) && (maxCard < 44) && (((*start >= maxCard) && (*start < 44)) || ((*start >= maxCard+3) && (*start < 47)) || ((*start >= maxCard+6) && (*start < 50)) || ((*start >= maxCard+9) && (*start < 53))))
                maxCard = *start;
            else if ((maxCard > 43) && (maxCard < 47) && (((*start >= maxCard) && (*start < 47)) || ((*start >= maxCard+3) && (*start < 50)) || ((*start >= maxCard+6) && (*start < 53))))
                maxCard = *start;
            else if ((maxCard > 46) && (maxCard < 50) && (((*start >= maxCard) && (*start < 50)) || ((*start >= maxCard+3) && (*start < 53))))
                maxCard = *start;
            else if ((maxCard > 49) && (maxCard < 53) && (*start >= maxCard) && (*start < 53))
                maxCard = *start;
            else if (*start > maxCard)
                maxCard = *start;
        }
    }
    return maxCard;
}
// An integer function to convert game card generated value to friendly value
int Card::cardEquality()
{
    cardValue = cardNum;
    if ((cardValue == 1) || (cardValue == 11) || (cardValue == 21) || (cardNum == 31))
        cardValue = 14;
    else if (cardValue > 40)
    {
        if ((cardValue > 40) && (cardValue < 44))
            cardValue -= 30;
        else if ((cardValue > 43) && (cardValue < 47))
            cardValue -= 33;
        else if ((cardValue > 46) && (cardValue < 50))
            cardValue -= 36;
        else
            cardValue -= 39;
    }
    else
    {
        if ((cardValue == 10) || (cardValue == 20) || (cardValue == 30) | (cardValue == 40))
        {
            cardValue = 10;
        }
        else
        {
            cardValue = cardValue % 10;
        }
    }
    return cardValue;
}
// An overloaded integer function to convert game card generated value to friendly value
int Card::cardEquality(int inputCard)
{
    if ((inputCard == 1) || (inputCard == 11) || (inputCard == 21) || (inputCard== 31))
        inputCard = 14;
    else if (inputCard > 40)
    {
        if ((inputCard > 40) && (inputCard < 44))
            inputCard -= 30;
        else if ((inputCard > 43) && (inputCard < 47))
            inputCard -= 33;
        else if ((inputCard > 46) && (inputCard < 50))
            inputCard -= 36;
        else
            inputCard -= 39;
    }
    else
    {
        if ((inputCard == 10) || (inputCard == 20) || (inputCard == 30) | (inputCard == 40))
        {
            inputCard = 10;
        }
        else
        {
            inputCard = inputCard % 10;
        }
    }
    return inputCard;
}
/// Problem paragraph 2 : Class Person as program base class
class Person
{
    public:
        Person(){basicInitialize();}
        virtual ~Person(){}
        /// Specification 1
        void basicInitialize();
        template <typename R>
        /// Feature 2 : Templates for type of function
        R Draw(int chLevel)
        {
            int drawTime = drawCalc(chLevel);
            return static_cast<R>(drawTime);
        }
        /// Feature 2 : Virtual functions
        virtual int drawCalc(int){}; /// Specification 1
        virtual char* Play(Card&, list <int> (&), bool){}
        /// Problem paragraph 2 : Class Person Drink() function
        bool Drink ();
        Person* next;
        Person* prev;
        string playerName;
        list <int> playerCards;
        int drinkLevel, cheatLevel, notches;
        bool aLive, drunk;
        char* thisTurnCard;
};
// Class Person initialize
void Person::basicInitialize()
{
        next = nullptr;
        prev = nullptr;
        playerName = "NULL";
        drinkLevel = 10;
        cheatLevel = 25;
        notches = 0;
        aLive = true;
        drunk = false;
        thisTurnCard = (char*)malloc(sizeof(char));
}
// A boolean function for character drink chance in normal situation
bool Person::Drink()
{
    bool getDrink = false;
    int chanceNum = rand() %100 + 1;
    /// Problem paragraph 2 : %10 chance to drink for who has full drink status
    if ((drinkLevel >= 100) && (chanceNum < 11))
    {
        getDrink = true;
    }
    /// Problem paragraph 5 : %5 chance to drink for who has not full drink status
    else if (chanceNum < 6)
    {
        getDrink = true;
    }
    return getDrink;
}
/// Problem paragraph 5 : Class PokerPlayer as Person derived class
class PokerPlayer : public Person
{
    public:
        char* Play(Card&, list <int> (&), bool);
};
/// Problem paragraph 3 : Class PokerPlayer virtual dynamic character function Play()
char* PokerPlayer::Play(Card (&gameCards), list <int> (&playerCards), bool drunk)
{
    char* thisCard = (char*)malloc(sizeof(char));
    int turnCard = gameCards.takeACard();
    if (drunk)
    {
        turnCard = gameCards.reducer(turnCard);
    }
    thisCard = gameCards.cardSurface(turnCard);
    turnCard = gameCards.cardEquality(turnCard);
    playerCards.push_back(turnCard);
    return thisCard;
}
/// Problem paragraph 3 : A derived class for cheat
class CardSharp : public Person
{
    public:
        /// Feature 2 : Templates for different function return type
        template<typename R>
        R Draw (int chLevel)
        {
            int drawTime = drawCalc(chLevel);
            return static_cast<R>(drawTime);
        }
        int drawCalc(int);
        char* Play(Card&, list <int> (&), bool);
};
/// Problem Paragraph 5 : CardSharp draw time
int CardSharp::drawCalc(int chLevel) /// Specification 1
{
    int drawTime = 0;
    int cheatTurn = 100;
    cheatTurn = rand() %100 + 1;
    if (cheatTurn <= chLevel)
    {
        drawTime = rand() %10 + 5;
        cout << "Cheating draw time : " << drawTime << " seconds" << endl;
    }
    return drawTime;
}
/// Problem Paragraph 5 : Cardsharp virtual dynamic function Play()
char* CardSharp::Play(Card (&gameCards), list <int> (&playerCards), bool drunk)
{
    char* thisCard = (char*)malloc(sizeof(char));
    int highest = gameCards.highestPlayed();
    thisCard = gameCards.cardSurface(highest);
    highest = gameCards.cardEquality(highest);
    playerCards.push_back(highest);
    return thisCard;
}
/// Problem paragraph 4 : Derived Class GunsLinger
class GunsLinger : public Person
{
    public:
        /// Feature 2 : Templates for different function return type
        template<typename R>
        R Draw(int chLevel)
        {
            int drawTime = drawCalc(chLevel);
            return static_cast<R>(drawTime);
        }
        /// Specification 1
        int drawCalc(int);
};
/// Problem paragraph 4 : Shooting peple draw time
int GunsLinger::drawCalc(int chLevel) /// Specification 1
{
    int drawTime = 0;
    int shootTurn = rand() % 100 + 1;
    if (shootTurn <= 50)
    {
        drawTime = rand() % 10 + 1;
    }
    return drawTime;
}
/// Problem paragraph 6 : A derived Class as Bartender
class Bartender : public Person
{
    public:
        /// Feature 2 : Templates for different function return type
        template<typename R>
        R Draw(int drLevel)
        {
            int drawTime = drawCalc(drLevel);
            return static_cast<R>(drawTime);
        }
        /// Specification 1
        int drawCalc(int);
};
/// Problem 6 : Bartender class Draw time
int Bartender::drawCalc(int drLevel) /// Specification 1
{
    if (drLevel < 100)
    {
        cout << "Wow! Bartender is pouring beer for this character!" << endl;
        return 1;
    }
    else
        return 0;
}
/// Problem paragraph 7 : A derived class for game's Saloon
class Saloon : public Person
{
    public:
        Saloon(){saloonInitialize();}
        ~Saloon();
        void saloonInitialize();
        //void deleteCharacter();
        void refullCharacters();
        void callplay();
        void displayCharacters();
        void printList(list <int>);
        void roundWinner();
        void winner();
    private:
        bool EOL, generateName, gameOver;
        int characterSize;
        Person* players;
        Person* lastPlayer;
        Person* deadCharacter;
        Person* currCharacter;
        Person* currPlayer;
        Person* nextPlayer;
        Card gameCards;
};
// Destructer
Saloon::~Saloon()
{
    delete players;
    lastPlayer = nullptr;
    players = nullptr;
    deadCharacter = nullptr;
    currCharacter = nullptr;
    currPlayer = nullptr;
    nextPlayer = nullptr;
}
/// Specification 3 & 4 : Start with 2 random players
// Saloon class initialize
void Saloon::saloonInitialize()
{
    gameOver = false;
    characterSize = 4;
    int startCharacterSize = 2;
    deadCharacter = nullptr;
    currCharacter = nullptr;
    currPlayer = nullptr;
    nextPlayer = nullptr;
    players = new Person;
    lastPlayer = players;
    generateName = true;
    int personNum = -1;
    int i;
    for (i = 0; i < startCharacterSize; i++)
    {
        generateName = true;
        while (generateName)
        {
            personNum = rand() %16;
            switch (personNum)
            {
                case 0:{lastPlayer->playerName = "Jimmy Carter"; break;}
                case 1:{lastPlayer->playerName = "The Shah of Iran"; break;}
                case 2:{lastPlayer->playerName = "James Callaghan"; break;}
                case 3:{lastPlayer->playerName = "Giscard d'Estaing"; break;}
                case 4:{lastPlayer->playerName = "Leonid Brezhnev"; break;}
                case 5:{lastPlayer->playerName = "Ronald Reagan"; break;}
                case 6:{lastPlayer->playerName = "Adolf Hitler"; break;}
                case 7:{lastPlayer->playerName = "The Pahlavi, Reza Shah"; break;}
                case 8:{lastPlayer->playerName = "Winston Churchill"; break;}
                case 9:{lastPlayer->playerName = "Franklin Roosevelt"; break;}
                case 10:{lastPlayer->playerName = "Joseph Stalin"; break;}
                case 11:{lastPlayer->playerName = "Benito Mussolini"; break;}
                case 12:{lastPlayer->playerName = "Vladimir Putin"; break;}
                case 13:{lastPlayer->playerName = "Kim Jong Un"; break;}
                case 14:{lastPlayer->playerName = "Donald Trump"; break;}
                case 15:{lastPlayer->playerName = "Saddam Hussein"; break;}
            }
            generateName = false;
            currCharacter = players;
            EOL = false;
            while ((!(EOL)) && (currCharacter->next))
            {
                if (currCharacter->playerName == lastPlayer->playerName)
                {
                    generateName = true;
                }
                if(currCharacter->next)
                    currCharacter = currCharacter->next;
                if (currCharacter == lastPlayer)
                    EOL = true;
                /// Feature 4 : Exceptions
                try
                {
                if (currCharacter == nullptr)
                    throw (currCharacter);
                }
                catch (Person* currCharacter)
                {
                    EOL = true;
                    cout << "Error 01: New node initializing for intro character fault!" << endl
                    << "Node address :" << currCharacter << endl;
                }
            }
        }
        if (i < (startCharacterSize-1))
        {
            lastPlayer->next = new Person;
            lastPlayer->next->prev = lastPlayer;
            lastPlayer = lastPlayer->next;
        }
        else
        {
            lastPlayer->next = players;
            players->prev = lastPlayer;
        }
    }
}
/*void Saloon::deleteCharacter()
{
    Person* temp = nullptr;
    if (deadCharacter != deadCharacter->prev)
    {
        deadCharacter = deadCharacter->prev;
        if (deadCharacter->next->next != deadCharacter)
        {
            deadCharacter->next = deadCharacter->next->next;
            deadCharacter->next->next->prev = deadCharacter;
        }
        else
        {
            deadCharacter->next = deadCharacter;
            deadCharacter->prev = deadCharacter;
        }
        if (temp == players)
        {
            players = players->next;
        }
        else if (temp == lastPlayer)
        {
            lastPlayer = lastPlayer->prev;
        }
        delete temp;
        temp = nullptr;
    }
    else //change
    {
        delete deadCharacter;
        deadCharacter = nullptr;
        lastPlayer = nullptr;
        players = nullptr;
        temp = nullptr;
    }
}*/
/// Problem Paragraph 7 :  Replace dead characters
void Saloon::refullCharacters()
{
    currCharacter = nullptr;
    int personNum = -1;
    int aLives = 0;
    generateName = true;
    currCharacter = players;
    EOL = false;
    while (!(EOL))
    {
        if (currCharacter->aLive)
            aLives++;
        currCharacter = currCharacter->next;
        if (currCharacter == players)
            EOL = true;
    }
    if (aLives < characterSize)
    {
        lastPlayer->next = new Person;
        lastPlayer->next->prev = lastPlayer;
        lastPlayer = lastPlayer->next;
        lastPlayer->next = players;
        players->prev = lastPlayer;
        while (generateName)
        {
            personNum = rand() %16;
            switch (personNum)
            {
                case 0:{lastPlayer->playerName = "Jimmy Carter"; break;}
                case 1:{lastPlayer->playerName = "The Shah of Iran"; break;}
                case 2:{lastPlayer->playerName = "James Callaghan"; break;}
                case 3:{lastPlayer->playerName = "Giscard d'Estaing"; break;}
                case 4:{lastPlayer->playerName = "Leonid Brezhnev"; break;}
                case 5:{lastPlayer->playerName = "Ronald Reagan"; break;}
                case 6:{lastPlayer->playerName = "Adolf Hitler"; break;}
                case 7:{lastPlayer->playerName = "The Pahlavi, Reza Shah"; break;}
                case 8:{lastPlayer->playerName = "Winston Churchill"; break;}
                case 9:{lastPlayer->playerName = "Franklin Roosevelt"; break;}
                case 10:{lastPlayer->playerName = "Joseph Stalin"; break;}
                case 11:{lastPlayer->playerName = "Benito Mussolini"; break;}
                case 12:{lastPlayer->playerName = "Vladimir Putin"; break;}
                case 13:{lastPlayer->playerName = "Kim Jong Un"; break;}
                case 14:{lastPlayer->playerName = "Donald Trump"; break;}
                case 15:{lastPlayer->playerName = "Saddam Hussein"; break;}
            }
            generateName = false;
            currCharacter = players;
            EOL = false;
            while (EOL == false)
            {
                if ((currPlayer->aLive) && (currCharacter->playerName == lastPlayer->playerName))
                {
                    generateName = true;
                }
                currCharacter = currCharacter->next;
                if (currCharacter == lastPlayer)
                {
                    EOL = true;
                }
                /// Feature 4 : Exceptions
                try
                {
                if (currCharacter == nullptr)
                    throw (currCharacter);
                }
                catch (Person* currCharacter)
                {
                    EOL = true;
                    cout << "Error 02: New node initializing for refill character fault!" << endl
                    << "Node address :" << currCharacter << endl;
                }
            }
        }
        cout << endl << "New player joined to game : " << lastPlayer->playerName << endl;
    }
}
/// Specification 2 : Operator << overloading
void operator<<(Person* current, string name)
{
    cout << "Player Name : " << name
    << "\t\tDrink level : %" << current->drinkLevel
    << setw(5) << " "
    << "Cheating level : %" << current->cheatLevel
    << setw(5) << " "
    << "Notches : " << current->notches <<  endl;
}
/// Operator >> overloading
void operator>>(Person* current, string name)
{
    cout << "Card : " << current->thisTurnCard << endl << endl;
}
/// Specification 5 : Show all characters at quit
void Saloon::displayCharacters()
{
    EOL = false;
    string deadStatus;
    int indexNum = 1;
    currCharacter = players;
    while (!(EOL))
    {
        cout << indexNum << ": ";
        currCharacter << currCharacter->playerName;
        if (currCharacter->aLive)
            deadStatus = "Alive";
        else
            deadStatus = "Dead";
        cout << "Life Status : " << deadStatus << endl << endl;
        currCharacter = currCharacter->next;
        indexNum++;
        if (currCharacter == players)
            EOL = true;
    }
    cout << endl;
}
// A module to print card lists
void Saloon::printList (list <int> toPrint)
{
    list <int>::iterator start;
    for (start = toPrint.begin(); start != toPrint.end(); start++)
    {
        cout << *start << " ";
    }
    cout << endl;
}
// A module to display a round winner
void Saloon::roundWinner()
{
    EOL = false;
    currCharacter = players;
    int highest = 0;
    string roundWinner;
    char* turnCard = (char*)malloc(sizeof(char));
    list <int>::iterator start;
    while (!(EOL))
    {
        if ((currCharacter->aLive == true) && (currCharacter->playerCards.back() > highest))
        {
            highest = currCharacter->playerCards.back();
            roundWinner = currCharacter->playerName;
            turnCard = currCharacter->thisTurnCard;
        }
        currCharacter = currCharacter->next;
        if (currCharacter == players)
        {
            EOL = true;
        }
    }
    cout << "Round winner : " << setw(15) << roundWinner << setw(10) << " " << "Card : " << turnCard << endl << endl;
}
// A module to display game winner
void Saloon::winner()
{
    EOL = false;
    currCharacter = players;
    int sum;
    int highest = 0;
    string gameWinner;
    list <int>::iterator start;
    while (!(EOL))
    {
        if (currCharacter->aLive)
        {
            sum = 0;
            for (start = currCharacter->playerCards.begin(); start != currCharacter->playerCards.end(); start++)
            {
                sum += *start;
            }
            if (sum > highest)
            {
                highest = sum;
                gameWinner = currCharacter->playerName;
            }
        }
        currCharacter = currCharacter->next;
        if (currCharacter == players)
        {
            EOL = true;
        }
    }
    cout << "Game winner : " << gameWinner << "\t\tScore : " << highest << endl << endl;
}
/// Problem paragraph 1 : Iterate through a dynamic memory structure of classes & callplay() to execute players actions every turn.
void Saloon::callplay()
{
    cout << "<Characters of West>" << endl << endl;
    int roundNum = 1;
    int cheatChance = 0;
    int thisFireChance = 0;
    int thatFireChance = 0;
    int index = 1;
    bool getDrink = false;
    bool bloodyRound = false;
    PokerPlayer normalPlay;
    CardSharp cheatPlay;
    GunsLinger openFire;
    Bartender beerPouring;
    currPlayer = players;
    while (gameCards.cards.size() < 52)
    {
        bloodyRound = false;
        EOL = false;
        currPlayer = players;
        index = 1;
        cout << endl << "<Round " << roundNum << ">" << endl << endl;
        while ((!(EOL)) && (gameCards.cards.size() < 52))
        {
            if (currPlayer->aLive)
            {
                /// Feature 4 : Exceptions
                try
                {
                    if (currPlayer == nullptr)
                        throw(currPlayer);
                }
                catch (Person* currunt)
                {
                    EOL = true;
                    cout << "Error 03 = Bad list allocation in callPlay() iteration!" << endl;
                }
                cout << index << "> ";
                currPlayer << currPlayer->playerName;
                cout << endl;
                getDrink = currPlayer->Drink();
                if (getDrink)
                {
                    cout << "Player had a drink ..." << endl
                    << "Cheat level increase by %5!" << endl
                    << "Drink level increased by %10!" << endl << endl;
                    currPlayer->drunk = true;
                    currPlayer->cheatLevel += 5;
                    currPlayer->drinkLevel += 10;
                    if (currPlayer->drinkLevel > 100)
                        currPlayer->drinkLevel = 100;
                    if (currPlayer->cheatLevel > 100)
                        currPlayer->cheatLevel = 100;
                    getDrink = false;
                }
                getDrink = beerPouring.Draw<bool>(currPlayer->drinkLevel);
                if (getDrink)
                {
                    cout << "Cheat level increase by %1!" << endl
                    << "Drink level increased by %3!" << endl << endl;
                    currPlayer->cheatLevel += 1;
                    currPlayer->drinkLevel += 3;
                    if (currPlayer->drinkLevel > 100)
                        currPlayer->drinkLevel = 100;
                    if (currPlayer->cheatLevel > 100)
                        currPlayer->cheatLevel = 100;
                    getDrink = false;
                }
                cheatChance = cheatPlay.Draw<int>(currPlayer->cheatLevel);
                /// Feature 3 : Asserts
                assert((cheatChance == 0) || ((cheatChance > 4) && (cheatChance < 16)));
                if ((cheatChance > 0) && (gameCards.cards.size() > 0))
                {
                    thisFireChance = openFire.Draw<int>(currPlayer->cheatLevel);
                    assert((thisFireChance > -1) && (thisFireChance < 11));
                    nextPlayer = currPlayer->next;
                    while (nextPlayer->aLive == false)
                    {
                        nextPlayer = nextPlayer->next;
                    }
                    thatFireChance = openFire.Draw<int>(nextPlayer->cheatLevel);
                    /// Feature 3 : Asserts
                    assert((thatFireChance > -1) && (thisFireChance < 11));
                    if (thatFireChance > 0)
                    {
                        if ((thisFireChance > 0) && (thisFireChance < thatFireChance))
                        {
                            cout << nextPlayer->playerName << " was shot and killed by " << currPlayer->playerName << " because he tried to kill him at first!" << endl
                            << "Shooting draw time : " << thisFireChance << " seconds" << endl;
                            currPlayer->thisTurnCard = cheatPlay.Play(gameCards ,currPlayer->playerCards, currPlayer->drunk);
                            if (currPlayer->notches < 10)
                                currPlayer->notches++;
                            nextPlayer->aLive = false;
                            bloodyRound = true;
                            EOL = true;
                        }
                        else if ((thisFireChance > thatFireChance) || (thisFireChance < 1))
                        {
                            cout << currPlayer->playerName << " was shot and killed by " << nextPlayer->playerName << " because his cheat!" << endl
                            << "Shooting draw time : " << thatFireChance << " seconds" << endl;
                            nextPlayer->thisTurnCard = cheatPlay.Play(gameCards ,nextPlayer->playerCards, nextPlayer->drunk);
                            if (nextPlayer->notches < 10)
                                nextPlayer->notches++;
                            currPlayer->aLive = false;
                            currPlayer = nextPlayer;
                            bloodyRound = true;
                            EOL = true;
                        }
                    }
                    else
                    {
                        currPlayer->thisTurnCard = cheatPlay.Play(gameCards ,currPlayer->playerCards, currPlayer->drunk);
                    }
                }
                else
                {
                    currPlayer->thisTurnCard = normalPlay.Play(gameCards ,currPlayer->playerCards, currPlayer->drunk);
                }
                currPlayer >> currPlayer->playerName;
                cout << endl;
                if (!(bloodyRound))
                {
                    currPlayer = currPlayer->next;
                    if (currPlayer == players)
                    {
                        EOL = true;
                    }
                }
                index++;
            }
            else
            {
                currPlayer = currPlayer->next;
                if (currPlayer == players)
                    EOL = true;
            }
        }
        if (!(bloodyRound))
            roundWinner();
        else
            cout << "Round winner : " << setw(15) << currPlayer->playerName << setw(10) << " " << "Card : " << currPlayer->thisTurnCard << endl << endl;
        roundNum++;
        refullCharacters();
    }
    winner();
    cout << endl << "Player List :" << endl << endl;
    displayCharacters();
}

int main()
{
    srand(time(0));
    Saloon game;
    game.callplay();
    return 0;
}
