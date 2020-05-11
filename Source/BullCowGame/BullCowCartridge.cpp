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
            if(Input == HiddenWord)
            {
                PrintLine(TEXT("You have won! "));
                EndGame();

            }else{
                if(Input.Len() != HiddenWord.Len())
                {
                    PrintLine(TEXT("The hidden word is %i character long, try again"), HiddenWord.Len());
                    EndGame();
                }else{
                    PrintLine(TEXT("Your guess is not the hidden word"));
                    EndGame();
                }
               
            }
        }
    
    
     
}
void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Welcome to Bull Cow!"));
    HiddenWord = TEXT("Honey"); // this is not input this is HiddenWord = "Honey"
    Lives = 4;
    bGameOver = false;

    
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("Enter your guess \nPress [ENTER] to continue..."));
}

void UBullCowCartridge::EndGame(){
    bGameOver = true;
    PrintLine(TEXT("Press [ENTER] to play again."));
}