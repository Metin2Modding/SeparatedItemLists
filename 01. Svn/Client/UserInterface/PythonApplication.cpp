// Find and delete:
snprintf(szItemList, sizeof(szItemList), "%s/item_list.txt", localePath);

// Next, find:
if (!rkItemMgr.LoadItemList(szItemList))
{
	// [...]
}

// And replace this condition with:
std::array<std::string, 2 /* Instead of two, you can set the number of files to be loaded. */> table =
{
	"item_list.txt",
	"another_item_list.txt"
	// If the above 2 has been changed to e.g. 3 then you add another file here.
	// Remember to include a comma after "another item_list.txt", but don't need to be added to the end of the table.
};

for (const auto& i : table)
{
	snprintf(szItemList, sizeof szItemList, i.c_str());

	if (!i.c_str())
		break;
	else
	{
		if (rkItemMgr.LoadItemList(i.c_str()))
			TraceError("LoadLocaleData -> LoadItemList -> Loaded file: %s", i.c_str());
		else
		{
			TraceError("LoadLocaleData -> LoadItemList -> Not loaded file: %s", i.c_str());
			continue;
		}
	}
}
