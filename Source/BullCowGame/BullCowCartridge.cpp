// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(Text("The hidden word is: %s."),*HiddenWord);
    PrintLine(TEXT("Welcome to Bull Cow!"));
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("Enter your guess and press [ENTER] to continue...1;"))
    SetupGame();
    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
     ClearScreen();
     
     if(Input == HiddenWord)
     {
         PrintLine(TEXT("You guessed right! "));

     }else{
         PrintLine(TEXT("It is wrong"));
     }
}
void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("Honey"); // this is not input this is HiddenWord = "Honey"
    Lives = 4;
}