#include "pch.h"
#include "unreal.h"

namespace unreal {
#pragma region Casting
	template <typename T> struct JTypeMapping {
		typedef T type;
		static inline const EJson enum_type;
	};

	template <> struct JTypeMapping<FJsonValueString> {
		typedef FJsonValueString type;
		static const EJson enum_type = EJson::String;
	};

	template<> struct JTypeMapping<FJsonValueArray> {

	};

	template<> struct JTypeMapping<FJsonValueObject> {

	};

	template<typename T> T* FJsonValue::cast(void) {
		if (this->type != JTypeMapping<T>::enum_type) {
			return;
		}
		return reinterpret_cast<T*>(this);
	}

#pragma endregion

#pragma region Accessors

	std::wstring FString::to_wstr(void) const {
		return std::wstring(this->data);
	}

	std::wstring FSparkRequest::get_url(void) const {
		return this->url.to_wstr();
	}

	std::wstring FJsonValueString::to_wstr(void) const {
		return this->str.to_wstr();
	}
#pragma endregion

#pragma region Explict Template Instantiation

	template FJsonValueString* FJsonValue::cast(void);
	template FJsonValueArray* FJsonValue::cast(void);
	template FJsonValueObject* FJsonValue::cast(void);

	template FJsonValueString* FJsonValueArray::get(uint32_t) const;
	template FJsonValueArray* FJsonValueArray::get(uint32_t) const;
	template FJsonValueObject* FJsonValueArray::get(uint32_t) const;

	template FJsonValueString* FJsonObject::get(std::wstring key) const;
	template FJsonValueArray* FJsonObject::get(std::wstring key) const;
	template FJsonValueObject* FJsonObject::get(std::wstring key) const;

#pragma endregion

}