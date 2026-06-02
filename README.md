# Winlator Topaz Video AI Patches

Custom Winlator build modified to run Topaz Video AI on Android (Snapdragon 870, Adreno 650).

## What's patched

1. **DXVK GPU spoofing** — `DXVKConfigDialog.java`: Adds `[Topaz*]` config block to spoof NVIDIA RTX 3060 with 4GB VRAM
2. **Registry spoofing** — `WineUtils.java`: Spoofs Intel i7-12700K CPU, 12 cores, 2GB RAM in Windows registry
3. **App workarounds** — `Win32AppWorkarounds.java`: Disables DirectML, sets MESA/VKD3D overrides for Topaz processes
4. **Box64 stability** — `default.box64rc`: Sets `BOX64_DYNAREC_STRONGMEM=2` for Topaz/msiexec/installer processes
5. **Environment & tmpfs** — `GuestProgramLauncherComponent.java`: Adds MESA overrides + 2GB tmpfs mount
6. **DirectML stub** — `directml.dll`: Returns `E_NOTIMPL` for DirectML calls, forcing fallback

## How to build

This repo contains patches — the GitHub Actions workflow will:
1. Clone upstream Winlator
2. Apply patches
3. Build the APK

Push to trigger the build, then download the APK from Actions → Artifacts.

## Manual build

```bash
git clone https://github.com/brunodev85/winlator.git --recursive
cd winlator
# Apply patches
cd app && git apply /path/to/patches/0001-topaz-video-ai.patch && cd ..
# Build
cd app && ANDROID_HOME=~/Android/Sdk ./gradlew assembleDebug
```
