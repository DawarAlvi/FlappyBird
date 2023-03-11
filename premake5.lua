workspace "FlappyBird"
    architecture "x64"
    configurations {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "FlappyBird"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir)

    files {
        "src/**.h",
        "src/**.hpp",
        "src/**.cpp"
    }

    includedirs {
        "include/",
        "src/"
    }

    libdirs {
        "lib/%{cfg.architecture}/"
    }

    links {
        "SDL2",
        "SDL2main",
        "SDL2_image"
    }

    postbuildcommands {
        "{COPY} lib/%{cfg.architecture}/SDL2.dll bin/"..outputdir,
        "{COPY} lib/%{cfg.architecture}/SDL2_image.dll bin/"..outputdir
    }

    filter { "system:windows" }
        systemversion "latest"
        files { 'resources.rc', '**.ico' }
        vpaths { ['data/sprites/*'] = { '*.rc', '**.ico' } }
    filter {}
    
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
  
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
