#include <Unary.Shear/Core/App.hpp>

#include <Unary.Shear/Systems/Arguments.hpp>
#include <Unary.Shear/Systems/TempFiles.hpp>
#include <Unary.Shear/Systems/IOContext.hpp>

#include <iostream>

namespace Unary::Shear::Core
{
	App* App::Instance = nullptr;

	void App::AddSys(eastl::vector<eastl::string>& Args)
	{
		AddSystem<Systems::Arguments>();
		GetSystem<Systems::Arguments>()->Set(Args);
		AddSystem<Systems::TempFiles>();
		AddSystem<Systems::IOContext>();


		//eastl::unordered_map<uint64_t, Variable> Test;

		//Invoke("Test", Test);



		;

		/*
		Add<Output>();
		Add<Build>();
		Add<Depots>();
		*/

		//StringSplit
	}

	bool App::Run()
	{
		while (Running)
		{

		}

		return true;
	}

    void App::Clear()
	{
		for (size_t i = Order.size(); i > 0; --i)
		{
			delete Systems[Order[i - 1]];
			Systems.erase(Order[i - 1]);
			Order.erase(Order.begin() + i - 1);
		}
	}

    template <typename T>
	T* App::AddSystem()
    {
		eastl::string TypeName = Utils::TypeAccessor<T>().GetType()->GetName();

		if (Systems.find(TypeName) != Systems.end())
		{
			Log.Message("Module " + TypeName + "is already registered.");
			return nullptr;
		}

		Systems[TypeName] = new T();
		Order.push_back(TypeName);

		return static_cast<T*>(Systems[TypeName]);
	}

    template <typename T>
	T* App::GetSystem()
	{
		eastl::string TypeName = Utils::TypeAccessor<T>().GetType()->GetName();

		auto Itr = Systems.find(TypeName);		
		
		if (Itr == Systems.end())
		{
			Log.Message("Could not find module " + TypeName + " .");
			return nullptr;
		}
		else
		{
			return static_cast<T*>(Itr->second);
		}
	}
}