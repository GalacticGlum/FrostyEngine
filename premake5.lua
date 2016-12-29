function setup_binaries(project_name)
    filter { "platforms:x86", "configurations:Debug" }
        targetdir ("Engine/Binaries/" .. project_name .. "/Debug/x86")
        objdir ("Engine/Intermediates/Build/" .. project_name .. "/Debug/x86")

    filter { "platforms:x64", "configurations:Debug" }
        targetdir ("Engine/Binaries/" .. project_name .. "/Debug/x64")
        objdir ("Engine/Intermediates/Build/" .. project_name .. "/Debug/x64")

    filter { "platforms:x86", "configurations:Release" }
        targetdir ("Engine/Binaries/" .. project_name .. "/Release/x86")
        objdir ("Engine/Intermediates/Build/" .. project_name .. "/Release/x86")

    filter { "platforms:x64", "configurations:Release" }
         targetdir ("Engine/Binaries/" .. project_name .. "/Release/x64")
         objdir ("Engine/Intermediates/Build/" .. project_name .. "/Release/x64")

    filter {}
end

workspace "Frosty Engine"
    location "."
    language "C++"
    platforms { "x64", "x86" }
    configurations { "Release", "Debug" }

    filter "configurations:Debug"
        symbols "On"
        optimize "Off"

    filter "configurations:Release"
        symbols "Off"
        optimize "Full"

    filter "platforms:x86"
        architecture "x86"
        libdirs "Engine/Third Party/Lib/*/x86"
        postbuildcommands { "xcopy /Y /C \"$(SolutionDir)Engine\\Third Party\\Lib\\GLFW\\x86\\*.dll\" \"$(OutDir)\"" } 
        postbuildcommands { "xcopy /Y /C \"$(SolutionDir)Engine\\Third Party\\Lib\\GLEW\\x86\\*.dll\" \"$(OutDir)\"" } 

    filter "platforms:x64"
        architecture "x86_64"
        libdirs "Engine/Third Party/Lib/*/x64"
        postbuildcommands { "xcopy /Y /C \"$(SolutionDir)Engine\\Third Party\\Lib\\GLFW\\x64\\*.dll\" $(OutDir)" } 
        postbuildcommands { "xcopy /Y /C \"$(SolutionDir)Engine\\Third Party\\Lib\\GLEW\\x64\\*.dll\" $(OutDir)" } 

    filter {}
        includedirs { "Engine/Third Party/Include", "Engine/Source/*/Public" }

    project "Sandbox"
        location "Engine/Intermediates/Project Files/"
        kind "ConsoleApp"
        files { "Engine/Source/Sandbox/**.cpp", "Engine/Source/Sandbox/**.h"  }
        links { "Common", "Core" }    

        filter "configurations:Release"
            links { "Common", "Core", "glfw3", "opengl32", "glew32s" }   
            defines "FROSTY_STATIC_LIBRARY"

        filter {}
            postbuildcommands { "xcopy \"$(SolutionDir)Engine\\Assets\" \"$(TargetDir)\\Assets\" /Y /S /D /I" }

        filter { "configurations:Debug", "platforms:x86" }
            postbuildcommands { 
                                "xcopy /Y /C \"$(SolutionDir)Engine\\Binaries\\Common\\Debug\\x86\\*.dll\" \"$(SolutionDir)Engine\\Binaries\\Sandbox\\Debug\\x86\"", 
                                "xcopy /Y /C \"$(SolutionDir)Engine\\Binaries\\Core\\Debug\\x86\\*.dll\" \"$(SolutionDir)Engine\\Binaries\\Sandbox\\Debug\\x86\""
                              }

        filter { "configurations:Debug", "platforms:x64" }
            postbuildcommands { 
                                "xcopy /Y /C \"$(SolutionDir)Engine\\Binaries\\Common\\Debug\\x64\\*.dll\" \"$(SolutionDir)Engine\\Binaries\\Sandbox\\Debug\\x64\"",
                                "xcopy /Y /C \"$(SolutionDir)Engine\\Binaries\\Core\\Debug\\x64\\*.dll\" \"$(SolutionDir)Engine\\Binaries\\Sandbox\\Debug\\x64\""
                              }
            
        filter {}

        setup_binaries "Sandbox"

    project "Common"
        location "Engine/Intermediates/Project Files/"
        files { "Engine/Source/Common/**.cpp", "Engine/Source/Common/**.h" }
        links {}

        filter "configurations:Debug"
            kind "SharedLib"
            defines "FROSTY_COMMON_EXPORTS"

        filter "configurations:Release"
            kind "StaticLib"
            defines "FROSTY_STATIC_LIBRARY"
            
        filter {}

        setup_binaries "Common"

    project "Core"
        location "Engine/Intermediates/Project Files/"
        files { "Engine/Source/Core/**.cpp", "Engine/Source/Core/**.h" }

        filter "configurations:Debug"  
            links { "Common", "glfw3dll", "opengl32", "glew32" }                       
            kind "SharedLib"
            defines "FROSTY_CORE_EXPORTS"

        filter "configurations:Release"
            kind "StaticLib"
            defines "FROSTY_STATIC_LIBRARY"

        filter {}

        setup_binaries "Core"
