#include <Unary.Make/Systems/Sys.hpp>

#include <Unary.Make/Systems/Arguments.hpp>
#include <Unary.Make/Systems/TempFiles.hpp>
#include <Unary.Make/Systems/Output.hpp>
#include <Unary.Make/Systems/Build.hpp>
#include <Unary.Make/Systems/Depots.hpp>

namespace Unary::Make::Systems
{
    bool Sys::Run(std::vector<std::string>* Args)
	{
		Add<Arguments>();

		if(!Get<Arguments>()->Set(Args))
		{
			return false;
		}

		Add<TempFiles>();
		Add<Output>();
		Add<Build>();
        Add<Depots>();

		return true;
	}

    void Sys::Clear()
	{
		for (size_t i = Order.size(); i > 0; --i)
		{
			Modules[Order[i - 1]]->Clear();
			delete Modules[Order[i - 1]];
			Modules.erase(Order[i - 1]);
			Order.erase(Order.begin() + i - 1);
		}
	}

    template <typename T>
	T* Sys::Add()
    {
		std::string TypeName = Utils::TypeAccessor<T>().GetType();

		if (Modules.find(TypeName) != Modules.end())
		{
			std::cout << "Module " + TypeName + " is already registered." << std::endl;
			return nullptr;
		}

		Modules[TypeName] = new T();
		Order.push_back(TypeName);

		Modules[TypeName]->SysPtr = this;
		Modules[TypeName]->Init();

		return static_cast<T*>(Modules[TypeName]);
	}

    template <typename T>
	T* Sys::Get()
	{
		std::string TypeName = Utils::TypeAccessor<T>().GetType();

		auto Itr = Modules.find(TypeName);		
		
		if (Itr == Modules.end())
		{
			std::cout << "Could not find module " + TypeName + " ." << std::endl;
			return nullptr;
		}
		else
		{
			return static_cast<T*>(Itr->second);
		}
	}
}