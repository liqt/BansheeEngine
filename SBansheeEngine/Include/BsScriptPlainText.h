#pragma once

#include "BsScriptEnginePrerequisites.h"
#include "BsScriptResource.h"
#include "BsScriptObject.h"
#include "BsPlainText.h"

namespace BansheeEngine
{
	/**
	 * @brief	Interop class between C++ & CLR for PlainText.
	 */
	class BS_SCR_BE_EXPORT ScriptPlainText : public TScriptResource<ScriptPlainText, PlainText>
	{
	public:
		SCRIPT_OBJ(ENGINE_ASSEMBLY, "BansheeEngine", "PlainText")

	private:
		friend class ScriptResourceManager;

		ScriptPlainText(MonoObject* instance, const HPlainText& plainText);

		/**
		 * @brief	Creates an empty, uninitialized managed instance of the resource interop object.
		 */
		static MonoObject* createInstance();

		/************************************************************************/
		/* 								CLR HOOKS						   		*/
		/************************************************************************/
		static void internal_createInstance(MonoObject* instance, MonoString* text);
		static MonoString* internal_getText(ScriptPlainText* thisPtr);
		static void internal_setText(ScriptPlainText* thisPtr, MonoString* text);
	};
}