// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Hello it is me"));
    PrintLine(TEXT("You need Macro TEXT to wrap the string"));
    InitGame();
    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
     ClearScreen();
     
     if(Input == HiddenWord)
     {
         PrintLine(TEXT("You guessed right! "));

     }else{
<<<<<<< Updated upstream
         PrintLine(TEXT("It is wrong"));
     }
=======
          ProcessGuess(Input) ;
        }

    
>>>>>>> Stashed changes
}
void UBullCowCartridge::InitGame()
{
    HiddenWord = TEXT("Honey"); // this is not input this is HiddenWord = "Honey"
<<<<<<< Updated upstream
    Lives = 4;
=======
    Lives = HiddenWord.Len();
    bGameOver = false;

    
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Enter your guess \nPress [ENTER] to continue..."));
}

void UBullCowCartridge::EndGame(){
    bGameOver = true;
    PrintLine(TEXT("Press [ENTER] to play again."));
    return;
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
     if(Guess == HiddenWord)
            {
                PrintLine(TEXT("You have won! "));
                EndGame();
                return;

            }
            if(Guess.Len() != HiddenWord.Len())
            {
                ClearScreen();
                PrintLine(TEXT("Lost a life!"));
                --Lives;
                PrintLine(TEXT("Sorry, try guessing again. \nYou have %i lives remain"),Lives);
                PrintLine(TEXT("The hidden word is %i character long, try again"), HiddenWord.Len());
                return;
            
            
            }
            
            if(Lives <= 0)
            {
                ClearScreen();
                PrintLine(TEXT("%i life"), Lives);
                PrintLine(TEXT("You have no life left!"));
                PrintLine(TEXT("The hidden word was %s."), *HiddenWord);
                EndGame();
                return;
            }

               
               
            
>>>>>>> Stashed changes
}