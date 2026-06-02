#include <windows.h>
#include <initguid.h>

/* Minimal DirectML stub — returns E_NOTIMPL so Topaz falls back to CPU */

HRESULT WINAPI DMLCreateDevice(
    void *d3d12Device,
    unsigned int flags,
    const IID *riid,
    void **ppv
) {
    if (ppv) *ppv = NULL;
    return 0x80004001L; /* E_NOTIMPL */
}

HRESULT WINAPI DMLCreateDevice1(
    void *d3d12Device,
    unsigned int flags,
    unsigned int minimumFeatureLevel,
    const IID *riid,
    void **ppv
) {
    if (ppv) *ppv = NULL;
    return 0x80004001L; /* E_NOTIMPL */
}

BOOL WINAPI DllMain(HINSTANCE hinst, DWORD reason, LPVOID reserved) {
    (void)hinst; (void)reason; (void)reserved;
    return TRUE;
}
