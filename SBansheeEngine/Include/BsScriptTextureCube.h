#pragma once

#include "BsScriptEnginePrerequisites.h"
#include "BsScriptTexture.h"
#include "BsScriptObject.h"
#include "BsTexture.h"

namespace BansheeEngine
{
	/**
	 * @brief	Interop class between C++ & CLR for a cube Texture.
	 */
	class BS_SCR_BE_EXPORT ScriptTextureCube : public TScriptResource <ScriptTextureCube, Texture>
	{
	public:
		SCRIPT_OBJ(ENGINE_ASSEMBLY, "BansheeEngine", "TextureCube")

	private:
		friend class ScriptResourceManager;

		ScriptTextureCube(MonoObject* instance, const HTexture& texture);

		/**
		 * @brief	Creates an empty, uninitialized managed instance of the resource interop object.
		 */
		static MonoObject* createInstance();

		/************************************************************************/
		/* 								CLR HOOKS						   		*/
		/************************************************************************/
		static void internal_createInstance(MonoObject* instance, PixelFormat format, UINT32 width,
			UINT32 height, TextureUsage usage, UINT32 numSamples, bool hasMipmaps, bool gammaCorrection);
		static MonoObject* internal_getPixels(ScriptTextureCube* thisPtr, UINT32 face, UINT32 mipLevel);
		static MonoObject* internal_getGPUPixels(ScriptTextureCube* thisPtr, UINT32 face, UINT32 mipLevel);
		static void internal_setPixels(ScriptTextureCube* thisPtr, MonoObject* data, UINT32 face, UINT32 mipLevel);
	};
}