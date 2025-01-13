#include "pch.h"
#include "Windows.Xbox.Storage.BlobInfoQueryResult.h"
#include "Windows.Xbox.Storage.BlobInfoQueryResult.g.cpp"
#include <winrt/Windows.Foundation.Collections.h>
#include "../ConnectedStorage/ConnectedStorage.h"
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Storage.FileProperties.h>
#include <hstring.h>

// WARNING: This file is automatically generated by a tool. Do not directly
// add this file to your project, as any changes you make will be lost.
// This file is a stub you can use as a starting point for your implementation.
//
// To add a copy of this file to your project:
//   1. Copy this file from its original location to the location where you store 
//      your other source files (e.g. the project root). 
//   2. Add the copied file to your project. In Visual Studio, you can use 
//      Project -> Add Existing Item.
//   3. Delete this comment and the 'static_assert' (below) from the copied file.
//      Do not modify the original file.
//
// To update an existing file in your project:
//   1. Copy the relevant changes from this file and merge them into the copy 
//      you made previously.
//    
// This assertion helps prevent accidental modification of generated files.
//////////static_assert(false, "This file is generated by a tool and will be overwritten. Open this error and view the comment for assistance.");

namespace winrt::Windows::Xbox::Storage::implementation
{
    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Storage::BlobInfo>> BlobInfoQueryResult::GetBlobInfoAsync(uint32_t startIndex, uint32_t maxNumberOfItems)
    {
        printf("GetBlobInfoAsync");
        co_await winrt::resume_background( );
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Storage::BlobInfo>> BlobInfoQueryResult::GetBlobInfoAsync()
    {
        winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Xbox::Storage::BlobInfo> blobInfoVector = winrt::single_threaded_vector<winrt::Windows::Xbox::Storage::BlobInfo>( );
        hstring s_prefix = prefix;

        hstring storagePath = winrt::Windows::Storage::ApplicationData::Current( ).LocalFolder( ).Path( ) + L"\\WinDurango\\UserStorage\\" + parentName;
        auto storageFolder = co_await winrt::Windows::Storage::StorageFolder::GetFolderFromPathAsync(storagePath);
        auto files = co_await storageFolder.GetFilesAsync( );

        printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\n\\\\\\\\\\\\\\\\\\\\\n");

        for (auto file : files) {
            // @Bagieta: if you know better way of checking this feel free to change this
            std::wstring_view str_view{ file.Name( ) };
            if (!str_view._Starts_with(s_prefix))
                continue;

            auto folderProperties = co_await file.GetBasicPropertiesAsync( );

            uint32_t size = folderProperties.Size( );

            blobInfoVector.Append({ file.Name( ), size});

            printf("Name -> %ls | Size -> %i\n", file.Name().c_str(), size);
        }
        printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\n\\\\\\\\\\\\\\\\\\\\\n");
        co_return blobInfoVector.GetView( );
    }
    winrt::Windows::Foundation::IAsyncOperation<uint32_t> BlobInfoQueryResult::GetItemCountAsync()
    {
        printf("GetItemCountAsync");
        co_await winrt::resume_background( );
    }
}
