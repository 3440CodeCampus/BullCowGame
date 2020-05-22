// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWords.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    IsIsogram = GetValidWords(Words);
    SetupGame();
    
}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
{
     if(bGameOver)
     {
        ClearScreen();
        SetupGame();
     }
     else
     {
         ProcessGuess(PlayerInput);
     }
}
   
void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Welcome to Bull Cows"));
    HiddenWord =  GetValidWords(Words)[FMath::RandRange(0, GetValidWords(Words).Num() - 1)];
    Lives = HiddenWord.Len() * 2;
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letters word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Type in your guess and \nPress enter to continue"));
    PrintLine(TEXT("The hidden word is %s"), *HiddenWord);
}
void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nPress enter to play again"));
}
void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
    if(Guess ==  HiddenWord)
    {
        PrintLine(TEXT("You have won!"));
        EndGame();
        return;
        
    }
    if(Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The Hidden word is %i letter long"), HiddenWord.Len());
        PrintLine(TEXT("Sorry try again! \nYou have %i lives remain"), Lives);
        return;
    }
    if(!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeat letter, Guess again"));
        return;
    }
    PrintLine(TEXT("Lost a life"));
    --Lives;
    if(Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no live left"));
        PrintLine(TEXT("The hidden word was %s."),*HiddenWord);
        EndGame();
        return;
    }
    FBullCowCount Score = GetBullCows(Guess);
    PrintLine(TEXT("You have %i Bulls and %i cows"), Score.Bulls, Score.Cows);
    PrintLine(TEXT("You have %i lives left, Guess again"), Lives);
    
    bool UBullCowCartridge::IsIsogram(const FString& Word) const
    {
        for(int32 Index = 0; Index < words.Len(); Index++)
        {
            for(int32 Compare = Index + 1; Compare < Word.Len(); Compare++)
            {
                if(Word[Index == Word[Compare])
                {
                    return false;
                }
            }
        }
        return true;
    }

}
TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
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
        if(Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word))
            {
                ValidWords.Emplace(Word);
            }
    }
    return ValidWords;
}

FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess) const
{
    FBullCowCount Count;
    for(int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
    {
        if(Guess[GuessIndex] == HiddenWord[GuessIndex])
        {
            Count.Bulls++;
            continue;
        }
        for(int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
        {
            Count.Cows++;
            break;
        }

    }
    return Count;
}