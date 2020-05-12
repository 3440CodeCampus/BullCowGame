// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
   // PrintLine(TEXT("The hidden word is: %s."),*HiddenWord); // debug line
    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
     if(bGameOver)
     {
         ClearScreen();
         SetupGame();
     }else{
          ProcessGuess(Input) ;
        }
    
}
void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Welcome to Bull Cow!-L34"));
    HiddenWord = TEXT("Honey"); // this is not input this is HiddenWord = "Honey"
    Lives = HiddenWord.Len();
    bGameOver = false;

    
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Enter your guess \nPress [ENTER] to continue..."));
}

void UBullCowCartridge::EndGame(){
    bGameOver = true;
    PrintLine(TEXT("Press [ENTER] to play again."));
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
                PrintLine(TEXT("Sorry, try guessing again. \nYou have %i lives remain"),Lives);
                PrintLine(TEXT("The hidden word is %i character long, try again"), HiddenWord.Len());
                EndGame();
                return;
            }
            PrintLine(TEXT("Lost a life!"));
            --Lives;
            
            if(Lives <= 0)
            {
                ClearScreen();
                PrintLine(TEXT("You have no life left!"));
                PrintLine(TEXT("The hidden word was %s."), *HiddenWord);
                EndGame();
                return;
            }

               
               
            
}