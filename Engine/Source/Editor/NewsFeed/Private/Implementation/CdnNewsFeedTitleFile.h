// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once


/**
 * CDN based title file implementation.
 * This code was salvaged from the deprecated EpicContent plug-in.
 */
class FCdnNewsFeedTitleFile
	: public TSharedFromThis<FCdnNewsFeedTitleFile, ESPMode::ThreadSafe>
	, public IOnlineTitleFile
{
	/** Info used to send request for a file */
	struct FPendingFileRequest
	{
		/**
		 * Constructor
		 */
		FPendingFileRequest(const FString& InFileName=FString(TEXT("")))
			:  FileName(InFileName)
		{

		}

		/**
		 * Equality op
		 */
		inline bool operator==(const FPendingFileRequest& Other) const
		{
			return FileName == Other.FileName;
		}

		/** File being operated on by the pending request */
		FString FileName;
	};

public:

	static IOnlineTitleFilePtr Create( const FString& IndexUrl );

public:

	// IOnlineTitleFile interface

	virtual bool GetFileContents(const FString& DLName, TArray<uint8>& FileContents) override;
	virtual bool ClearFiles() override;
	virtual bool ClearFile(const FString& DLName) override;
	virtual void DeleteCachedFiles(bool bSkipEnumerated) override;
	virtual bool EnumerateFiles(const FPagedQuery& Page = FPagedQuery()) override;
	virtual void GetFileList(TArray<FCloudFileHeader>& InFileHeaders) override;
	virtual bool ReadFile(const FString& DLName) override;

protected:
	
	/**
	 * Delegate called when a Http request completes for enumerating list of file headers
	 */
	void EnumerateFiles_HttpRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);

	/**
	 * Delegate called when a Http request completes for reading a cloud file
	 */
	void ReadFile_HttpRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);

	/**
	 * Find/create cloud file entry 
	 *
	 * @param FileName cached file entry to find
	 * @param bCreateIfMissing create the file entry if not found
	 *
	 * @return cached cloud file entry
	 */
	FCloudFile* GetCloudFile(const FString& FileName, bool bCreateIfMissing);

	/**
	 * Find cloud file header entry 
	 *
	 * @param FileName cached file entry to find
	 *
	 * @return cached cloud file header entry
	 */
	FCloudFileHeader* GetCloudFileHeader( const FString& FileName);

	/**
	 * Converts filename into a local file cache path
	 *
	 * @param FileName name of file being loaded
	 *
	 * @return unreal file path to be used by file manager
	 */
	FString GetLocalFilePath(const FString& FileName);

	/**
	 * Save a file from a given user to disk
	 *
	 * @param FileName name of file being saved
	 * @param Data data to write to disk
	 */
	void SaveCloudFileToDisk(const FString& Filename, const TArray<uint8>& Data);

private:

	/**
	 * Should use the initialization constructor instead
	 */
	FCdnNewsFeedTitleFile( const FString& InIndexUrl );

private:

	// Config based url for enumerating list of cloud files.
	FString EnumerateFilesUrl;
	
	// Config based url for downloading/updating a single cloud file entry.
	FString FileUrl;

	// List of pending Http requests for enumerating files.
	TQueue<IHttpRequest*> EnumerateFilesRequests;

	// List of pending Http requests for reading files.
	TMap<class IHttpRequest*, FPendingFileRequest> FileRequests;

	TArray<FCloudFileHeader> FileHeaders;
	TArray<FCloudFile> Files;

	FString IndexUrl;
};
