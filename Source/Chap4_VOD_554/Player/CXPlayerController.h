// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Chap4_VOD_554.h"

#include "GameFramework/PlayerController.h"

#include "CXPlayerController.generated.h"


class UCXChatInput;
class UUserWidget;

/**
 * 
 */
UCLASS()
class CHAP4_VOD_554_API ACXPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACXPlayerController();

	virtual void BeginPlay() override;

	void SetChatMessageString(const FString& InChatMessageString);

	void PrintChatMessageString(const FString& InChatMessageString);

	UFUNCTION(Client, Reliable)
	void ClientRPCPrintChatMessageString(const FString& InChatMessageString);

	UFUNCTION(Server, Reliable)
	void ServerRPCPrintChatMessageString(const FString& InChatMessageString);

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(Replicated, BlueprintReadOnly)
	FText NotificationText;


protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UCXChatInput> ChatInputWidgetClass;

	UPROPERTY()
	TObjectPtr<UCXChatInput> ChatInputWidgetInstance;

	FString ChatMessageString;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> NotificationTextWidgetClass;

	UPROPERTY()
	TObjectPtr<UUserWidget> NotificationTextWidgetInstance;

};
