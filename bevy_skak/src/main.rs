use bevy::prelude::*;
use bevy_chess::BevyChessPlugin;
use interface::InterfacePlugin;

mod bevy_chess;
mod interface;


fn main() {
    App::new()
        .add_plugins((
            InterfacePlugin,
            BevyChessPlugin,
            // EguiPlugin {
            //     enable_multipass_for_primary_context: true,
            // },
            // WorldInspectorPlugin::new(),
        ))
        .run();
}