#pragma once

class USUtils
{
public:
	template<typename T>
	static T* GetUSPlayerComponent(APawn* PlayerPawn)
	{
		if (!PlayerPawn)
			return nullptr;

		const auto Component = PlayerPawn->GetComponentByClass(T::StaticClass());
		return Cast<T>(Component);
	}
};