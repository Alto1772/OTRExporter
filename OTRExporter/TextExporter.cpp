#include "TextExporter.h"
#include "../ZAPD/ZFile.h"

void OTRExporter_Text::Save(ZResource* res, const fs::path& outPath, BinaryWriter* writer)
{
	ZText* txt = (ZText*)res;

	WriteHeader(txt, outPath, writer, Ship::ResourceType::Text);

	auto start = std::chrono::steady_clock::now();

	//printf("Exporting Texture %s\n", tex->GetName().c_str());

	writer->Write((uint32_t)txt->messages.size());
	
	for (int i = 0; i < txt->messages.size(); i++)
	{
		writer->Write(txt->messages[i].id);
		writer->Write(txt->messages[i].textboxType);
		writer->Write(txt->messages[i].textboxYPos);
		writer->Write(txt->messages[i].msg);
	}
}
