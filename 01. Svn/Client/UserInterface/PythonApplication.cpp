// Find and delete:
char szItemList[256];

// Find and delete:
snprintf(szItemList, sizeof(szItemList), "%s/item_list.txt", localePath);

// Next, replace this condition:
if (!rkItemMgr.LoadItemList(szItemList))
{
	// [...]
}

// With:
std::vector<std::string> table =
{
	"txt/etc_list.txt",
	"txt/weapon_list.txt"
};

for (const auto& i : table)
{
	char szItemList[256];
	snprintf(szItemList, sizeof szItemList, i.c_str());

	if (rkItemMgr.LoadItemList(i.c_str()))
		TraceError("LoadLocaleData -> LoadItemList -> Loaded file: %s", i.c_str());
	else
	{
		TraceError("LoadLocaleData -> LoadItemList -> Not loaded file: %s", i.c_str());
		continue;
	}
}
