// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWords.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("There are %i words in the list"),Words.Num());
    PrintLine(TEXT("There are %i valid words"), GetValidWords(Words).Num());
    // for(int32 Index = 0; Index <= 10; Index++)
    // {
    //     if(Words[Index].Len() >= 4 && Words[Index].Len() <= 8 )
    //     PrintLine(TEXT("%s"), *Words[Index]);
    // }
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

TArray<FString> UBullCowCartridge::GetValidWords(TArray<FString> WordList) const
{
    TArray<FString> ValidWords;
    // 傳統 方法 遂個 loop 過去 //
    ////////////////////////////
    // for(int32 Index = 0; Index < WordList.Num(); Index++)
    // {
    //     if(WordList[Index].Len() >= 4 && WordList[Index].Len() <= 8)
    //     {
    //         ValidWords.Emplace(WordList[Index]);
    //     }
    // }
    // 不必 loop //
    //////////////
    for (FString Word: WordList)
    {
        if(Word.Len() >= 4 && Word.Len() <= 8)
            {
                ValidWords.Emplace(Word);
            }
    }
    return ValidWords;
}