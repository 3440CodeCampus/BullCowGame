// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWords.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("There are %i words in the list"),Words.Num());
    // PrintLine(TEXT("Hello it is me"));
    // PrintLine(TEXT("You need Macro TEXT to wrap the string"));
    // InitGame();
    
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
void UBullCowCartridge::InitGame()
{
    HiddenWord = TEXT("Honey"); // this is not input this is HiddenWord = "Honey"
    Lives = 4;
}