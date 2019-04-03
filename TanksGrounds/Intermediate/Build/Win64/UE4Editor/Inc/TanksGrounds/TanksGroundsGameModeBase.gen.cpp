// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TanksGrounds/TanksGroundsGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTanksGroundsGameModeBase() {}
// Cross Module References
	TANKSGROUNDS_API UClass* Z_Construct_UClass_ATanksGroundsGameModeBase_NoRegister();
	TANKSGROUNDS_API UClass* Z_Construct_UClass_ATanksGroundsGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_TanksGrounds();
// End Cross Module References
	void ATanksGroundsGameModeBase::StaticRegisterNativesATanksGroundsGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ATanksGroundsGameModeBase_NoRegister()
	{
		return ATanksGroundsGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ATanksGroundsGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATanksGroundsGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_TanksGrounds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATanksGroundsGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "TanksGroundsGameModeBase.h" },
		{ "ModuleRelativePath", "TanksGroundsGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATanksGroundsGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATanksGroundsGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATanksGroundsGameModeBase_Statics::ClassParams = {
		&ATanksGroundsGameModeBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A8u,
		METADATA_PARAMS(Z_Construct_UClass_ATanksGroundsGameModeBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATanksGroundsGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATanksGroundsGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATanksGroundsGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATanksGroundsGameModeBase, 497169657);
	template<> TANKSGROUNDS_API UClass* StaticClass<ATanksGroundsGameModeBase>()
	{
		return ATanksGroundsGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATanksGroundsGameModeBase(Z_Construct_UClass_ATanksGroundsGameModeBase, &ATanksGroundsGameModeBase::StaticClass, TEXT("/Script/TanksGrounds"), TEXT("ATanksGroundsGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATanksGroundsGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
