use serde::{Deserialize, Serialize};
use serde_json;
use std::{fs,path::Path};
use anyhow;

#[derive(Serialize, Deserialize)]
struct FontsSet{
    font_family: String,
    size: String,
    ligature: bool,
}
#[derive(Serialize, Deserialize)]
pub struct Value{
    config_version: String,
    themes: String,
    fonts_set: FontsSet,
    enable_plug: Vec<String>,
    plug: Vec<String>,
}


impl Value{
    #[no_mangle]
    extern "C" fn read_user_config(&mut self) -> anyhow::Result<()>{
        let config_path:&Path = Path::new("~/.QianDengLake/config.json");
        let config_config = &fs::read_to_string(config_path)? as &str;
        let serde_config:Value = serde_json::from_str(config_config)?;

        self.config_version = serde_config.config_version;
        self.themes = serde_config.themes;
        self.fonts_set = serde_config.fonts_set;
        self.enable_plug = serde_config.enable_plug;
        self.plug = serde_config.plug;

        Ok(())
    }
    #[no_mangle]
    extern "C" fn write_user_config(&self) -> anyhow::Result<()>{
        let config_path:&Path = Path::new("~/.QianDengLake/config.json");
        let change_config = serde_json::to_string(self);
        fs::write(config_path, change_config.unwrap().as_bytes())?;

        Ok(())
    }
}