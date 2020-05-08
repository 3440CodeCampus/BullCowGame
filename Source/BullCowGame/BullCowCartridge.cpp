// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Hello it is me"));
    PrintLine(TEXT("You need Macro TEXT to wrap the string"));
    HiddenWord = TEXT("Honey"); // this is not input this is HiddenWord = "Honey"
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