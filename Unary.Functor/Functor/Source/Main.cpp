#include <iostream>
#include <unordered_map>
#include <steam/steam_api.h>

/*
// 1446220 - Functor
// 1436420 - Recusant

class CGameManager
{
public:

    //We create a new Item by providing the game ID and we specify we are creating a normal mod that can be subscribed to
    void CreateItem()
    {
        std::cout << "Creating item..." << std::endl;

        SteamAPICall_t hSteamAPICall = SteamUGC()->CreateItem(nConsumerAppID, k_EWorkshopFileTypeCommunity);
        m_CreateItemResult.Set(hSteamAPICall, this, &CGameManager::onItemCreated);
    }

    bool finished = false;
    AppId_t nConsumerAppID = (AppId_t)1446220;
    PublishedFileId_t File;

private:
    void onItemCreated(CreateItemResult_t* pCallback, bool bIOFailure);
    void onItemSubmitted(SubmitItemUpdateResult_t* pCallback, bool bIOFailure);

    CCallResult<CGameManager, CreateItemResult_t> m_CreateItemResult;
    CCallResult<CGameManager, SubmitItemUpdateResult_t> m_SubmitItemUpdateResult;
};



//Once the mod was created, we can grab the id from the callback params and then customize it with the UGCUpdateHandle_t before making another API call to SubmitItemUpdate
void CGameManager::onItemCreated(CreateItemResult_t* pCallback, bool bIOFailure)
{
    if (pCallback->m_eResult == k_EResultOK && !bIOFailure)
    {
        std::cout << "Item created!" << std::endl;

        if (pCallback->m_bUserNeedsToAcceptWorkshopLegalAgreement)
        {
            SteamFriends()->ActivateGameOverlayToWebPage("steam://url/CommunityFilePage/");
        }

        UGCUpdateHandle_t handle = SteamUGC()->StartItemUpdate(nConsumerAppID, pCallback->m_nPublishedFileId);

        SteamUGC()->SetItemTitle(handle, "Title test");
        SteamUGC()->SetItemDescription(handle, "Description test");
        //SteamUGC()->SetItemVisibility(handle, ERemoteStoragePublishedFileVisibility::k_ERemoteStoragePublishedFileVisibilityPublic);

        std::string mod_directory = "C:/Users/ilyas/Documents/Klei";
        SteamUGC()->SetItemContent(handle, mod_directory.c_str());
        std::string preview_image = "C:/Users/ilyas/Desktop/ded.jpg";
        SteamUGC()->SetItemPreview(handle, preview_image.c_str());

        std::string pchChangeNote = "This is a changelog";

        SteamAPICall_t submit_item_call = SteamUGC()->SubmitItemUpdate(handle, pchChangeNote.c_str());
        m_SubmitItemUpdateResult.Set(submit_item_call, this, &CGameManager::onItemSubmitted);

        File = pCallback->m_nPublishedFileId;
    }
    else
    {
        finished = true;
    }
}

void CGameManager::onItemSubmitted(SubmitItemUpdateResult_t* pCallback, bool bIOFailure)
{
    if (pCallback->m_eResult == k_EResultOK && !bIOFailure)
    {
        std::cout << "Item update submitted created!" << std::endl;
    }
    else
    {
        std::cout << "Item update submit failed!" << std::endl;
        EResult TestRes = pCallback->m_eResult;
        ;
    }
    finished = true;
}

static std::unordered_map<int, std::string> Status =
{
    {0, "Invalid"},
    {1, "PreparingConfig"},
    {2, "PreparingContent"},
    {3, "UploadingContent"},
    {4, "UploadingPreviewFile"},
    {5, "CommittingChanges"}
};




int main()
{
    //First, let's check if the Steam client is running
    if (SteamAPI_Init())
    {
        CGameManager gameManager;
        //Now let's trigger the item creation process
        gameManager.CreateItem();

        //Dont forget to run the callbacks while we wait
        while (!gameManager.finished)
        {
            SteamAPI_RunCallbacks();
            uint64_t Processed;
            uint64_t Total;
            EItemUpdateStatus NewStatus = SteamUGC()->GetItemUpdateProgress(gameManager.File, &Processed, &Total);
            std::cout << '[' << Status[NewStatus] << "] " << Processed << " / " << Total << std::endl;
        }
    }

    std::cout << "Process finished" << std::endl;

    return 0;
}

*/

#include <Functor/MyApp.hpp>

int main() {
    MyApp app;
    app.Run();

    return 0;
}